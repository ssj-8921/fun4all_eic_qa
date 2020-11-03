#include "EvalCluster.h"

#include <calobase/RawCluster.h>

#include <CLHEP/Vector/ThreeVector.h>

EvalCluster::EvalCluster(const RawCluster *clus)
{
  ce = clus->get_energy();
  CLHEP::Hep3Vector cluspos = clus->get_position();
  ceta = cluspos.getEta();
  ctheta = cluspos.getTheta();
  cphi = cluspos.getPhi();
}
