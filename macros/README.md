# macros

First you need to source the eic setup script to get your environment and set up your local installation (if you have one). If you use csh/tcsh as your shell, use the .csh scripts, if you have bash use the .sh scripts:

* csh/tcsh:
```
  source /cvmfs/eix.opensciencegrid.org/x8664_sl7/opt/fun4all/core/bin/eic_setup.csh
  source $OPT_FUN4ALL/bin/setup_local.csh <install area>
```


* bash:

```
  source /cvmfs/eix.opensciencegrid.org/x8664_sl7/opt/fun4all/core/bin/eic_setup.sh
  source $OPT_FUN4ALL/bin/setup_local.sh <install area>
```

Run the macro:
```
  root.exe
  .x Fun4All_G4_EICDetector.C(<number of events>)
```

By default all detectors and evaluators are enabled as is the dumping of the output data into a ROOT TTree (DSTReader). Commenting out the Enable setting will disable a given module. Modules which depend on it will also be disabled. Absorbers (passive volumes) can either be enabled by a setting for each detector or globally by 
```
  Enable::ABSORBER = true;
```
 The QA is configures in the macro G4_QA.C where the 