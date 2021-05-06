# fun4all_eic_qa/source

## classes:

  * QAExample: Example template to start with your own QA historgramming code

  * QAG4SimulationEicCalorimeter: Calorimeter QA code

## How to build:
First you need to source the eic setup script to get your environment and set up your local installation (if you have one). If you use csh/tcsh as your shell, use the .csh scripts, if you have bash use the .sh scripts:

* csh/tcsh:
```
  source /cvmfs/eic.opensciencegrid.org/x8664_sl7/opt/fun4all/core/bin/eic_setup.csh
```

* bash:

```
  source /cvmfs/eic.opensciencegrid.org/x8664_sl7/opt/fun4all/core/bin/eic_setup.sh
```

In rcf accounts typically are set up by their experiment (STAR, PHENIX) and their definitions of e.g. ROOTSYS interferes with ours. Adding a -n flag to the script will reset existing environment variables which interfere with our settings. Also use this if you want to reset your environment. Using -n does not have negative effects if it is not needed - it just resets your environment to the default:
```
  source /cvmfs/eic.opensciencegrid.org/x8664_sl7/opt/fun4all/core/bin/eic_setup.csh -n
```

You need three separate areas, the source area (<srcdir> where you cloned this to), the build area (<builddir> which you have to create) and the install area (<installdir>where the compiled libraries and include files are installed. You want to use only one install area, no matter how many packages you build. Otherwise you'll probably get interdependencies wrong. The install area will be created if it does not exist.

Creating a Makefile:

We use the autotools to prepare the code for compilation. You need to create a build directory, cd to it and

```
<srcdir>/autogen.sh --prefix=<installdir>
```

will create the Makefile. For <srcdir> use the full path, this enables the debugger to find your source files (and you will need to use a debugger eventually). Then make and install your binaries (using 10 parallel build processes if you have many sources):

```
make -j 10 install
```

Then don't forget to add your installation area to your paths (.sh if you use bash):

```
  source $OPT_FUN4ALL/bin/setup_local.csh <install area>
```

You have to do this only once not every time you recompile.
