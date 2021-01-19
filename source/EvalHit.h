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

  float get_xin() const { return xin; }

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
