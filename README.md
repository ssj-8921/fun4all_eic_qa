# fun4all_eic_qa
The QA package for the EIC specific detectors. The code is in source, the macros to run the show are in macros. See the README.md in the respective directories for details. This package is part of our daily build. If you just want to run the macros, you can do so without having to compile anything.

## macros

  * Fun4All_G4_EICDetector.C: EIC detector based on the Babar magnet

## source

  * QAG4SimulationEicCalorimeter: Calorimeter QA

  * QAExample: Example template to make your own

## How to work with this (you do need a github account)

  First you should create your own fork of this repository. Then you have your own copy and can work with it. You'll find the Fork button in the upper right corner. Then you can clone your repository to your local host:

```
git clone https://github.com/<your github account>/fun4all_eic_qa
```

Now you cd to the fun4all_eic_qa area and establish a link to the upstream eic repo (needed if you want to resync with the upstream repo or make pull requests):

```
git remote add upstream https://github.com/eic/fun4all_eic_qa
```

Now you can work with your repo, modify and commit code without interfering with the upstream repo. If you want to save your changes to github, use

```
git push origin master
```

This also allows us to give you support. In case things don't work we can just clone your repo and run it to see what's wrong.

```
git remote -v

git fetch upstream
git rebase upstream/master

git push origin master
```
