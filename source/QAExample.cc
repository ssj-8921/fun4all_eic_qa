#include "QAExample.h"

#include <qa_modules/QAHistManagerDef.h>

#include <g4main/PHG4Particle.h>
#include <g4main/PHG4TruthInfoContainer.h>

#include <fun4all/Fun4AllHistoManager.h>
#include <fun4all/Fun4AllReturnCodes.h>
#include <fun4all/SubsysReco.h>

#include <phool/getClass.h>

#include <TH1.h>
#include <TH2.h>

#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>      // for map
#include <utility>  // for pair

using namespace std;

QAExample::QAExample(const std::string &name)
  : SubsysReco(name)
{
}

int QAExample::InitRun(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

int QAExample::Init(PHCompositeNode *topNode)
{
  Fun4AllHistoManager *hm = QAHistManagerDef::getHistoManager();
  assert(hm);

  // reco pT / gen pT histogram
  TH1 *h(nullptr);

  h = new TH1F(TString(get_histo_prefix()) + "pT",
               "pT", 500, 0, 20);
  hm->registerHisto(h);

  h = new TH2F(TString(get_histo_prefix()) + "pTpz",
               "pT vs pz", 200, 0, 50, 500, 0, 20);
  //  QAHistManagerDef::useLogBins(h->GetXaxis());
  hm->registerHisto(h);

  return Fun4AllReturnCodes::EVENT_OK;
}

int QAExample::process_event(PHCompositeNode *topNode)
{
  if (Verbosity() > 2)
    cout << "QAExample::process_event() entered" << endl;

  // load relevant nodes from NodeTree
  load_nodes(topNode);

  // histogram manager
  Fun4AllHistoManager *hm = QAHistManagerDef::getHistoManager();
  assert(hm);

  // reco pT / gen pT histogram
  TH1 *pT = dynamic_cast<TH1 *>(hm->getHisto(get_histo_prefix() + "pT"));
  assert(pT);

  // reco pT / gen pT histogram
  TH2 *pTpz = dynamic_cast<TH2 *>(hm->getHisto(get_histo_prefix() + "pTpz"));
  assert(pTpz);

  // fill histograms that need truth information
  if (!m_truthContainer)
  {
    cout << "QAExample::process_event - fatal error - missing m_truthContainer! ";
    return Fun4AllReturnCodes::ABORTRUN;
  }

  PHG4TruthInfoContainer::ConstRange range = m_truthContainer->GetPrimaryParticleRange();
  for (PHG4TruthInfoContainer::ConstIterator iter = range.first; iter != range.second; ++iter)
  {
    // get the truth particle information
    PHG4Particle *g4particle = iter->second;

    if (Verbosity())
    {
      cout << "QAExample::process_event - processing ";
      g4particle->identify();
    }

    double gpx = g4particle->get_px();
    double gpy = g4particle->get_py();
    double pt = sqrt(gpx * gpx + gpy * gpy);
    double gpz = g4particle->get_pz();
    pT->Fill(pt);
    pTpz->Fill(pt, gpz);
  }
  return Fun4AllReturnCodes::EVENT_OK;
}

int QAExample::load_nodes(PHCompositeNode *topNode)
{
  m_truthContainer = findNode::getClass<PHG4TruthInfoContainer>(topNode, "G4TruthInfo");
  if (!m_truthContainer)
  {
    cout << "QAExample::load_nodes - Fatal Error - "
         << "unable to find DST node "
         << "G4TruthInfo" << endl;
    assert(m_truthContainer);
  }

  return Fun4AllReturnCodes::EVENT_OK;
}

string
QAExample::get_histo_prefix()
{
  return string("h_") + Name() + string("_");
}
