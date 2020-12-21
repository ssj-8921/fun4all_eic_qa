#ifndef EVALTOWER_H
#define EVALTOWER_H

#include <phool/PHObject.h>

#include <cmath>

class RawTower;

class EvalTower : public PHObject
{
 public:
  EvalTower(const RawTower *twr);
  virtual ~EvalTower() {}

  void set_te(const float f) { te = f; }
  void set_teta(const float f) { teta = f; }
  void set_tt(const float f) { tt = f; }
  void set_ttheta(const float f) { ttheta = f; }
  void set_tphi(const float f) { tphi = f; }
  void set_tx(const float f) { tx = f; }
  void set_ty(const float f) { ty = f; }

 private:
  float te = NAN;
  float teta = NAN;
  float tphi = NAN;
  float tt = NAN;
  float ttheta = NAN;
  float tx = NAN;
  float ty = NAN;

  ClassDef(EvalTower, 1)
};

#endif
