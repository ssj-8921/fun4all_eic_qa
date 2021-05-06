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

 root.exe -q -b LoopEvalMultiFCircularCut.C\(0,1\) > FHCAL_FEMC_CircularCut.txt
 
 echo Done





