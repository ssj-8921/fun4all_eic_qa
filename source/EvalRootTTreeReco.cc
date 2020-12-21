
#include "EvalRootTTreeReco.h"

#include "EvalHit.h"
#include "EvalRootTTree.h"
#include "EvalTower.h"

#include <g4main/PHG4Hit.h>
#include <g4main/PHG4HitContainer.h>
#include <g4main/PHG4Particle.h>
#include <g4main/PHG4TruthInfoContainer.h>
#include <g4main/PHG4VtxPoint.h>

#include <calobase/RawCluster.h>
#include <calobase/RawClusterContainer.h>
#include <calobase/RawTower.h>
#include <calobase/RawTowerContainer.h>
#include <calobase/RawTowerGeom.h>
#include <calobase/RawTowerGeomContainer.h>

#include <fun4all/Fun4AllReturnCodes.h>

#include <phool/PHCompositeNode.h>
#include <phool/getClass.h>

#include <TSystem.h>

#include <iostream>  // for operator<<, endl, basic_ost...

//____________________________________________________________________________..
EvalRootTTreeReco::EvalRootTTreeReco(const std::string &name)
  : SubsysReco(name)
{
}

//____________________________________________________________________________..
EvalRootTTreeReco::~EvalRootTTreeReco()
{
}

//____________________________________________________________________________..
int EvalRootTTreeReco::Init(PHCompositeNode *topNode)
{
  if (m_Detector.empty())
  {
    std::cout << "Detector not set via Detector(<name>) method" << std::endl;
    std::cout << "(it is the name appended to the G4HIT_<name> nodename)" << std::endl;
    std::cout << "you do not want to run like this, exiting now" << std::endl;
    gSystem->Exit(1);
  }
  PHNodeIterator iter(topNode);
  PHCompositeNode *dstNode = dynamic_cast<PHCompositeNode *>(iter.findFirst("PHCompositeNode", "DST"));
  EvalRootTTree *evaltree = new EvalRootTTree();
  PHIODataNode<PHObject> *node = new PHIODataNode<PHObject>(evaltree, m_OutputNode, "PHObject");
  dstNode->addNode(node);
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int EvalRootTTreeReco::InitRun(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int EvalRootTTreeReco::process_event(PHCompositeNode *topNode)
{
  PHG4TruthInfoContainer *truthinfo = findNode::getClass<PHG4TruthInfoContainer>(topNode, "G4TruthInfo");

  EvalRootTTree *evaltree = findNode::getClass<EvalRootTTree>(topNode, m_OutputNode);
  PHG4VtxPoint *gvertex = truthinfo->GetPrimaryVtx(truthinfo->GetPrimaryVertexIndex());
  evaltree->set_gvx(gvertex->get_x());
  evaltree->set_gvy(gvertex->get_y());
  evaltree->set_gvz(gvertex->get_z());
  PHG4TruthInfoContainer::ConstRange range = truthinfo->GetPrimaryParticleRange();
  int justone = 0;
  for (PHG4TruthInfoContainer::ConstIterator iter = range.first;
       iter != range.second;
       ++iter)
  {
    justone++;
    PHG4Particle *primary = iter->second;
    double gpx = primary->get_px();
    double gpy = primary->get_py();
    double gpz = primary->get_pz();
    double gpt = std::sqrt(gpx * gpx + gpy * gpy);
    double gmom = std::sqrt(gpx * gpx + gpy * gpy + gpz * gpz);

    evaltree->set_gpx(gpx);
    evaltree->set_gpy(gpy);
    evaltree->set_gpz(gpz);
    evaltree->set_ge(primary->get_e());
    evaltree->set_gpid(primary->get_pid());
    double geta = NAN;
    if (gpt > 0)
    {
      geta = asinh(gpz / gpt);
    }
    evaltree->set_geta(geta);
    evaltree->set_gphi(atan2(gpy, gpx));
    evaltree->set_gtheta(acos(gpz / gmom));
  }
  if (justone > 1)
  {
    std::cout << "this only works for single particle events"
              << " here I see " << justone << " primaries" << std::endl;
    gSystem->Exit(1);
  }

  // add hits
  PHG4HitContainer *g4hits = findNode::getClass<PHG4HitContainer>(topNode, m_HitNodeName);

  if (g4hits)
  {
    evaltree->set_nhits(g4hits->size());
    PHG4HitContainer::ConstRange hit_range = g4hits->getHits();
    for (PHG4HitContainer::ConstIterator hit_iter = hit_range.first; hit_iter != hit_range.second; hit_iter++)
    {
      evaltree->AddHit(hit_iter->second);
    }
  }

  // add towers
  RawTowerGeomContainer *rawtowergeomcontainer = findNode::getClass<RawTowerGeomContainer>(topNode, m_TowerGeoNodeName);

  RawTowerContainer *g4towers = findNode::getClass<RawTowerContainer>(topNode, m_TowerNodeName);
  if (g4towers)
  {
    evaltree->set_ntowers(g4towers->size());
    RawTowerContainer::ConstRange tower_range = g4towers->getTowers();
    for (RawTowerContainer::ConstIterator tower_iter = tower_range.first; tower_iter != tower_range.second; tower_iter++)
    {
      RawTower *twr = tower_iter->second;
      EvalTower *evaltwr = evaltree->AddTower(twr);
      RawTowerGeom *geom = rawtowergeomcontainer->get_tower_geometry(twr->get_key());
      evaltwr->set_eta(geom->get_eta());
      evaltwr->set_theta(geom->get_theta());
      evaltwr->set_phi(geom->get_phi());
    }
  }
  // Clusters
  RawClusterContainer *clusters = findNode::getClass<RawClusterContainer>(topNode, m_ClusterNodeName);
  if (clusters)
  {
    evaltree->set_nclusters(clusters->size());
    for (const auto &iterator : clusters->getClustersMap())
    {
      RawCluster *cluster = iterator.second;
      evaltree->AddCluster(cluster);
    }
  }

  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int EvalRootTTreeReco::ResetEvent(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int EvalRootTTreeReco::EndRun(const int runnumber)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int EvalRootTTreeReco::End(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int EvalRootTTreeReco::Reset(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
void EvalRootTTreeReco::Print(const std::string &what) const
{
  std::cout << "EvalRootTTreeReco::Print(const std::string &what) const Printing info for " << what << std::endl;
}

void EvalRootTTreeReco::Detector(const std::string &name)
{
  m_Detector = name;
  m_OutputNode = "EvalTTree_" + name;
  m_HitNodeName = "G4HIT_" + name;
  m_TowerNodeName = "TOWER_SIM_" + name;
  m_TowerGeoNodeName = "TOWERGEOM_" + name;
  m_ClusterNodeName = "CLUSTER_" + name;
}
