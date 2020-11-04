#include <eicqa_modules/EvalRootTTreeReco.h>

#include <fun4all/Fun4AllServer.h>
#include <fun4all/Fun4AllInputManager.h>
#include <fun4all/Fun4AllDstInputManager.h>
#include <fun4all/Fun4AllDstOutputManager.h>
#include <fun4all/Fun4AllOutputManager.h>

R__LOAD_LIBRARY(libfun4all.so)
R__LOAD_LIBRARY(libeicqa_modules.so)

void RunEval(const std::string &detector, const std::string &fname, const int nevnt = 0)
{
  gSystem->Load("libg4dst");
  std::string outfile = "Eval_" + detector + ".root";
  std::string outnode = "EvalTTree_" + detector;
  Fun4AllServer *se = Fun4AllServer::instance();
  EvalRootTTreeReco *eval = new EvalRootTTreeReco();
  eval->Detector(detector);
  se->registerSubsystem(eval);
  Fun4AllInputManager *in = new Fun4AllDstInputManager("QAin");
  in->fileopen(fname);
  se->registerInputManager(in);
  Fun4AllDstOutputManager *out = new Fun4AllDstOutputManager("DSTOUT", outfile);
  out->AddNode(outnode);
  out->SaveRunNode(0);
  se->registerOutputManager(out);
  if (nevnt < 0)
  {
    return;
  }
  se->run(nevnt);
  se->End();
  delete se;
  gSystem->Exit(0);
}
