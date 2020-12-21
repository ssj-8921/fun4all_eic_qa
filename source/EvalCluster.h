#ifndef EVALCLUSTER_H
#define EVALCLUSTER_H

#include <phool/PHObject.h>

#include <cmath>

class RawCluster;

class EvalCluster : public PHObject
{
 public:
  EvalCluster(const RawCluster *twr);
  virtual ~EvalCluster() {}

  void set_ctowers(const int i) {ctowers = i;}

  void set_ce(const float f) {ce = f;}
  void set_ceta(const float f) {ceta = f;}
  void set_cphi(const float f) {cphi = f;}
  void set_ctheta(const float f) {ctheta = f;}
  void set_cx(const float f) {cx = f;}
  void set_cy(const float f) {cy = f;}

 private:
  int ctowers = 0;
  float ce = NAN;
  float ceta = NAN;
  float cphi = NAN;
  float ctheta = NAN;
  float cx = NAN;
  float cy = NAN;

  ClassDef(EvalCluster, 1)
};

#endif
