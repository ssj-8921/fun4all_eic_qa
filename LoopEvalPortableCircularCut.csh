#!/usr/local/bin/tcsh
 setenv HOME /eic/u/$LOGNAME
 source /etc/csh.login
 foreach i (/etc/profile.d/*.csh)
   source $i
 end
 source $HOME/.login
 source /cvmfs/eic.opensciencegrid.org/default/opt/fun4all/core/bin/eic_setup.csh -n
  
 printenv
  # this is how you run your Fun4All_G4_sPHENIX.C macro in batch: 

 root.exe -q -b 'LoopEvalPortableCircularCut.C("CEMC", 0, 1)' > CEMC_CircularCut.txt
 root.exe -q -b 'LoopEvalPortableCircularCut.C("EEMC", 0, 1)' > EEMC_CircularCut.txt
 root.exe -q -b 'LoopEvalPortableCircularCut.C("FEMC", 0, 1)' > FEMC_CircularCut.txt
 root.exe -q -b 'LoopEvalPortableCircularCut.C("FHCAL", 0, 1)' > FHCAL_CircularCut.txt
 root.exe -q -b 'LoopEvalPortableCircularCut.C("HCALIN", 0, 1)' > HCALIN_CircularCut.txt
 root.exe -q -b 'LoopEvalPortableCircularCut.C("HCALOUT", 0, 1)' > HCALOUT_CircularCut.txt
 
 echo Done





