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

 private:
  float ceta = NAN;
  float ctheta = NAN;
  float cphi = NAN;
  float ce = NAN;

  ClassDef(EvalCluster, 1)
};

#endif
