#include "EvalCluster.h"

#include <calobase/RawCluster.h>

#include <CLHEP/Vector/ThreeVector.h>

EvalCluster::EvalCluster(const RawCluster *clus)
{
  ce = clus->get_energy();
  ctowers = clus->getNTowers();
  cx = clus->get_x();
  cy = clus->get_y();
  CLHEP::Hep3Vector cluspos = clus->get_position();
  ceta = cluspos.getEta();
  cphi = cluspos.getPhi();
  ctheta = cluspos.getTheta();
}
