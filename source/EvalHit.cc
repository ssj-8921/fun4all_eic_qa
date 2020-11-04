#include "EvalHit.h"

#include <g4main/PHG4Hit.h>

EvalHit::EvalHit(const PHG4Hit *g4hit)
{
  detid = g4hit->get_detid();
  trackid = g4hit->get_trkid();
  xin = g4hit->get_x(0);
  yin = g4hit->get_y(0);
  zin = g4hit->get_z(0);
  tin = g4hit->get_t(0);
  xout = g4hit->get_x(1);
  yout = g4hit->get_y(1);
  zout = g4hit->get_z(1);
  tout = g4hit->get_t(1);
  edep = g4hit->get_edep();
  eion = g4hit->get_eion();
  light_yield = g4hit->get_light_yield();
}
