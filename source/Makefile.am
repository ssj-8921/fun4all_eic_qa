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
  QAExample.h \
  QAG4SimulationEicCalorimeter.h

libeicqa_modules_la_SOURCES = \
  QAExample.cc \
  QAG4SimulationEicCalorimeter.cc

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
