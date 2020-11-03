#include "EvalRootTTree.h"

#include "EvalHit.h"

#include <g4main/PHG4Hit.h>      // for PHG4Hit

#include <TClonesArray.h>

static const int NMAX = 100000;

EvalRootTTree::EvalRootTTree()
{
  SnglHits = new TClonesArray("EvalHit",NMAX);
}

EvalRootTTree::~EvalRootTTree()
{
  SnglHits->Clear();
  delete SnglHits;
}

void EvalRootTTree::Reset()
{
  SnglHits->Clear();
  if (SnglHits->GetSize() > NMAX)
  {
    SnglHits->Expand(NMAX);
  }
  event = 0;
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
    SnglHits->Expand(SnglHits->GetSize() + NMAX/10);
  }
  new (cl[nextindex]) EvalHit(g4hit);
  return (static_cast<EvalHit *>(cl[nextindex]));
}
