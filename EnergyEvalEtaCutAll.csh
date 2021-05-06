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

 root.exe -q -b EnergyEvalEtaCut.C\(\"CEMC\", 0, 1\) > Energy_CEMC.txt
 root.exe -q -b EnergyEvalEtaCut.C\(\"EEMC\", 0, 1\) > Energy_EEMC.txt
 root.exe -q -b EnergyEvalEtaCut.C\(\"FEMC\", 0, 1\) > Energy_FEMC.txt
 root.exe -q -b EnergyEvalEtaCut.C\(\"FHCAL\", 0, 1\) > Energy_FHCAL.txt
 root.exe -q -b EnergyEvalEtaCut.C\(\"HCALIN\", 0, 1\) > Energy_HCALIN.txt
 root.exe -q -b EnergyEvalEtaCut.C\(\"HCALOUT\", 0, 1\) > Energy_HCALOUT.txt

 echo EnergyEvalEtaCut Plots Produced 
