#ifndef EVALCLUSTER_H
#define EVALCLUSTER_H

#include <phool/PHObject.h>

#include <cmath>

class RawCluster;

class EvalCluster : public PHObject
{
 public:
  // ctor with no args to make root happy
  EvalCluster() {}
  EvalCluster(const RawCluster *twr);
  virtual ~EvalCluster() {}

  void set_ctowers(const int i) { ctowers = i; }
  int get_ctowers() const { return ctowers; }

  void set_ce(const float f) { ce = f; }
  float get_ce() const { return ce; }

  void set_ceta(const float f) { ceta = f; }
  float get_ceta() const { return ceta; }

  void set_cphi(const float f) { cphi = f; }
  float get_cphi() const { return cphi; }

  void set_ctheta(const float f) { ctheta = f; }
  float get_ctheta() const { return ctheta; }

  void set_cx(const float f) { cx = f; }
  float get_cx() const { return cx; }

  void set_cy(const float f) { cy = f; }
  float get_cy() const { return cy; }

  void set_cz(const float f) { cz = f; }
  float get_cz() const { return cz; }

 private:
  int ctowers = 0;
  float ce = NAN;
  float ceta = NAN;
  float cphi = NAN;
  float ctheta = NAN;
  float cx = NAN;
  float cy = NAN;
  float cz = NAN;

  ClassDef(EvalCluster, 1)
};

#endif
