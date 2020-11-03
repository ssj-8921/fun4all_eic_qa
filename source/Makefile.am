AUTOMAKE_OPTIONS = foreign

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include \
  -I$(OFFLINE_MAIN)/include/eigen3 \
  -I`root-config --incdir`

lib_LTLIBRARIES = \
   libeicqa_modules.la

libeicqa_modules_la_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib

libeicqa_modules_la_LIBADD = \
  -lqa_modules

pkginclude_HEADERS = \
  EvalRootTTree.h \
  EvalRootTTreeReco.h \
  QAExample.h \
  QAG4SimulationEicCalorimeter.h \
  QAG4SimulationEicCalorimeterSum.h

ROOTDICTS = \
  EvalHit_Dict.cc \
  EvalRootTTree_Dict.cc

pcmdir = $(libdir)
nobase_dist_pcm_DATA = \
  EvalHit_Dict_rdict.pcm \
  EvalRootTTree_Dict_rdict.pcm

libeicqa_modules_la_SOURCES = \
  $(ROOTDICTS) \
  EvalHit.cc \
  EvalRootTTree.cc \
  EvalRootTTreeReco.cc \
  QAExample.cc \
  QAG4SimulationEicCalorimeter.cc \
  QAG4SimulationEicCalorimeterSum.cc

# Rule for generating table CINT dictionaries.
%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

#just to get the dependency
%_Dict_rdict.pcm: %_Dict.cc ;

################################################
# linking tests

noinst_PROGRAMS = testexternals

BUILT_SOURCES = \
  testexternals.cc

testexternals_SOURCES = \
  testexternals.cc

testexternals_LDADD = \
  libeicqa_modules.la

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

clean-local:
	rm -f *Dict* testexternals.cc
