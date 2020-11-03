#ifndef EVALTOWER_H
#define EVALTOWER_H

#include <phool/PHObject.h>

#include <cmath>

class RawTower;

class EvalTower: public PHObject
{

public:
  EvalTower(const RawTower *twr);
  virtual ~EvalTower() {}

  void set_eta(const float f) {teta = f;}
  void set_theta(const float f) {ttheta = f;}
  void set_phi(const float f) {tphi = f;}

 private:
  float teta = NAN;
  float ttheta = NAN;
  float tphi = NAN;
  float te = NAN;
  float tt = NAN;

  ClassDef(EvalTower, 1)
};

#endif
