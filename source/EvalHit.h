#ifndef EVALHIT_H
#define EVALHIT_H

#include <phool/PHObject.h>

#include <cmath>

class PHG4Hit;

class EvalHit : public PHObject
{
 public:
  // ctor with no args to make root happ
  EvalHit() {}

  EvalHit(const PHG4Hit *g4hit);
  virtual ~EvalHit() {}

  int get_detid() const { return detid; }
  int get_trackid() const { return trackid; }

  float get_xin() const { return xin; }
  float get_xout() const { return xout; }

  float get_yin() const { return yin; }
  float get_yout() const { return yout; }

  float get_zin() const { return zin; }
  float get_zout() const { return zout; }

  float get_tin() const { return tin; }
  float get_tout() const { return tout; }

  float get_edep() const { return edep; }
  float get_eion() const { return eion; }
  float get_light_yield() const { return light_yield; }

 private:
  int detid = -9999;
  int trackid = 0;
  float xin = NAN;
  float xout = NAN;
  float yin = NAN;
  float yout = NAN;
  float zin = NAN;
  float zout = NAN;
  float tin = NAN;
  float tout = NAN;
  float edep = NAN;
  float eion = NAN;
  float light_yield = NAN;

  ClassDef(EvalHit, 1)
};

#endif
