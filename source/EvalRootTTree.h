#ifndef EVALROOTTTREE_H
#define EVALROOTTTREE_H

#include <phool/PHObject.h>

#include <cmath>

class EvalHit;
class EvalTower;
class EvalCluster;
class PHG4Hit;
class RawTower;
class RawCluster;
class TClonesArray;

class EvalRootTTree : public PHObject
{
 public:
  EvalRootTTree();
  virtual ~EvalRootTTree();
  void Reset();

  EvalHit* AddHit(const PHG4Hit* g4hit);
  EvalTower* AddTower(const RawTower* twr);
  EvalCluster* AddCluster(const RawCluster* clus);

  void set_event_number(const int i) { event = i; }
  int get_event_number() const { return event;}

  void set_gpid(const int i) { gpid = i; }
  int get_gpid() const { return gpid;}

  void set_gvx(const double v) { gvx = v; }
  double get_gvx() const { return gvx;}

  void set_gvy(const double v) { gvy = v; }
  double get_gvy() const { return gvy;}

  void set_gvz(const double v) { gvz = v; }
  double get_gvz() const { return gvz;}

  void set_gpx(const double p) { gpx = p; }
  double get_gpx() const { return gpx;}

  void set_gpy(const double p) { gpy = p; }
  double get_gpy() const { return gpy;}

  void set_gpz(const double p) { gpz = p; }
  double get_gpz() const { return gpz ;}

  void set_ge(const double p) { ge = p; }
  double get_ge() const { return ge;}

  void set_geta(const double d) { geta = d; }
  double get_geta() const { return geta;}

  void set_gphi(const double d) { gphi = d; }
  double get_gphi() const { return gphi;}

  void set_gtheta(const double d) { gtheta = d; }
  double get_gtheta() const { return gtheta ;}

// calorimeter hits, get hit class, hit accessors are in hit class
  void set_nhits(const int n) { nhits = n; }
  int get_nhits() const {return nhits;}
  EvalHit *get_hit(const size_t i) const;

  void set_ntowers(const int n) { ntowers = n; }
  int get_ntowers() const { return ntowers;}
  EvalTower* get_tower(const size_t i) const;

  void set_nclusters(const int n) { nclusters = n; }
  int get_nclusters() const { return nclusters;}
  EvalCluster* get_cluster(const size_t i) const;

 private:
  TClonesArray* SnglHits = nullptr;
  TClonesArray* SnglTowers = nullptr;
  TClonesArray* SnglClusters = nullptr;

  int event = 0;
  int gpid = -99999;
  int nhits = 0;
  int ntowers = 0;
  int nclusters = 0;
  double gvx = NAN;
  double gvy = NAN;
  double gvz = NAN;
  double gpx = NAN;
  double gpy = NAN;
  double ge = NAN;
  double gpz = NAN;
  double geta = NAN;
  double gphi = NAN;
  double gtheta = NAN;

  ClassDef(EvalRootTTree, 1)
};

#endif
