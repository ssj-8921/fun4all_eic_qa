#ifndef EVALHIT_H
#define EVALHIT_H

#include <phool/PHObject.h>

#include <cmath>

class PHG4Hit;

class EvalHit : public PHObject
{

public:
  EvalHit(const PHG4Hit *g4hit);
  virtual ~EvalHit() {}

  /* void set_trkid(const int i) {trackid = i;} */
  /* void set_x(const int i, const float f) {x[i] = f;} */
  /* void set_y(const int i, const float f) {y[i] = f;} */
  /* void set_z(const int i, const float f) {z[i] = f;} */
  /* void set_t(const int i, const float f) {t[i] = f;} */

  /* void set_edep(const float f) {edep = f;} */
  /* void set_eion(const float f) {eion = f;} */
  /* void set_light_yield(const float f) {light_yield = f;} */

  float get_xin() const {return xin;}

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

  ClassDef(EvalHit,1)
};

#endif
