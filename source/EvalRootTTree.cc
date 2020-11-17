#include "EvalRootTTree.h"

#include "EvalCluster.h"
#include "EvalHit.h"
#include "EvalTower.h"

#include <g4main/PHG4Hit.h>  // for PHG4Hit

#include <calobase/RawCluster.h>
#include <calobase/RawTower.h>

#include <TClonesArray.h>

static const int NHIT = 100000;
static const int NTWR = 100;
static const int NCLU = 100;

EvalRootTTree::EvalRootTTree()
{
  SnglHits = new TClonesArray("EvalHit", NHIT);
  SnglTowers = new TClonesArray("EvalTower", NTWR);
  SnglClusters = new TClonesArray("EvalCluster", NCLU);
}

EvalRootTTree::~EvalRootTTree()
{
  SnglHits->Clear();
  delete SnglHits;
  SnglTowers->Clear();
  delete SnglTowers;
  SnglClusters->Clear();
  delete SnglClusters;
}

void EvalRootTTree::Reset()
{
  SnglHits->Clear();
  if (SnglHits->GetSize() > NHIT)
  {
    SnglHits->Expand(NHIT);
  }
  SnglTowers->Clear();
  if (SnglTowers->GetSize() > NTWR)
  {
    SnglTowers->Expand(NTWR);
  }
  SnglClusters->Clear();
  if (SnglClusters->GetSize() > NTWR)
  {
    SnglClusters->Expand(NTWR);
  }
  event = 0;
  gpid = -99999;
  gvx = NAN;
  gvy = NAN;
  gvz = NAN;
  gpx = NAN;
  gpy = NAN;
  ge = NAN;
  gpz = NAN;
  geta = NAN;
  gphi = NAN;
  gtheta = NAN;
}

EvalHit *
EvalRootTTree::AddHit(const PHG4Hit *g4hit)
{
  TClonesArray &cl = *SnglHits;
  int nextindex = SnglHits->GetLast() + 1;
  if (nextindex == SnglHits->GetSize())
  {
    SnglHits->Expand(SnglHits->GetSize() + NHIT / 10);
  }
  new (cl[nextindex]) EvalHit(g4hit);
  return (static_cast<EvalHit *>(cl[nextindex]));
}

EvalTower *
EvalRootTTree::AddTower(const RawTower *twr)
{
  TClonesArray &cl = *SnglTowers;
  int nextindex = SnglTowers->GetLast() + 1;
  if (nextindex == SnglTowers->GetSize())
  {
    SnglTowers->Expand(SnglTowers->GetSize() + NTWR / 10);
  }
  new (cl[nextindex]) EvalTower(twr);
  return (static_cast<EvalTower *>(cl[nextindex]));
}

EvalCluster *
EvalRootTTree::AddCluster(const RawCluster *clus)
{
  TClonesArray &cl = *SnglClusters;
  int nextindex = SnglClusters->GetLast() + 1;
  if (nextindex == SnglClusters->GetSize())
  {
    SnglClusters->Expand(SnglClusters->GetSize() + NCLU / 10);
  }
  new (cl[nextindex]) EvalCluster(clus);
  return (static_cast<EvalCluster *>(cl[nextindex]));
}
