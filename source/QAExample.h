#ifndef QA_QAEXAMPLE_H
#define QA_QAEXAMPLE_H

#include <g4eval/SvtxEvalStack.h>

#include <trackbase/TrkrDefs.h>  // for cluskey

#include <fun4all/SubsysReco.h>

#include <memory>
#include <set>
#include <string>
#include <utility>

class PHCompositeNode;
class PHG4TruthInfoContainer;

/// \class QAExample
class QAExample : public SubsysReco
{
 public:
  QAExample(const std::string &name = "QAExample");
  virtual ~QAExample() = default;

  int Init(PHCompositeNode *topNode);
  int InitRun(PHCompositeNode *topNode);
  int process_event(PHCompositeNode *topNode);

  // common prefix for QA histograms
  std::string get_histo_prefix();


 private:
  /// load nodes
  int load_nodes(PHCompositeNode *);


  PHG4TruthInfoContainer *m_truthContainer = nullptr;
};

#endif  // QA_QAEXAMPLE_H
