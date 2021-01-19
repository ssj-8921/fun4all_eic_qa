#ifndef EVALTOWER_H
#define EVALTOWER_H

#include <phool/PHObject.h>

#include <cmath>

class RawTower;

class EvalTower : public PHObject
{
 public:
  // ctor with no args to make root happy
  EvalTower() {}
  EvalTower(const RawTower *twr);
  virtual ~EvalTower() {}

  void set_te(const float f) { te = f; }
  float get_te() const { return te; }

  void set_teta(const float f) { teta = f; }
  float get_teta() const { return teta; }

  void set_tt(const float f) { tt = f; }
  float get_tt() const { return tt; }

  void set_ttheta(const float f) { ttheta = f; }
  float get_ttheta() const { return ttheta; }

  void set_tphi(const float f) { tphi = f; }
  float get_tphi() const { return tphi; }

  void set_tx(const float f) { tx = f; }
  float get_tx() const { return tx; }

  void set_ty(const float f) { ty = f; }
  float get_ty() const { return ty; }

  void set_tz(const float f) { tz = f; }
  float get_tz() const { return tz; }

 private:
  float te = NAN;
  float teta = NAN;
  float tphi = NAN;
  float tt = NAN;
  float ttheta = NAN;
  float tx = NAN;
  float ty = NAN;
  float tz = NAN;

  ClassDef(EvalTower, 1)
};

#endif
