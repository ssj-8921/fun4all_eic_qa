#include "EvalTower.h"

#include <calobase/RawTower.h>

EvalTower::EvalTower(const RawTower *twr)
{
  tt = twr->get_time();
  te = twr->get_energy();
}
