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

To look at the repositories use

```
git remote -v
```

you will see

```
origin  git@github.com:<your github username>/fun4all_eic_qa (fetch)
origin  git@github.com:<your github username>/fun4all_eic_qa (push)
upstream        git@github.com:eic/fun4all_eic_qa (fetch)
upstream        git@github.com:eic/fun4all_eic_qa (push)
```

You should keep a backup of you repository around (nothing fancy, e.g. usign rsync into a separate directory is enough). Especially in the beginning you will make mistakes where the easiest recovery is to just copy you repo back from a backup.

to resync with the upstream repository:

```
# first check out your master branch
git checkout master
# fetch the upstream changes
git fetch upstream
# play changes of upstream on your master branch
git rebase upstream/master
# push the updated master branch to your github repo
git push origin master
```

Now you can work with your repo, modify and commit code without interfering with the upstream repo. If you want to resync with the upstream repo

If you want to save the updated version back to github, use

```
git push origin master
```

For your own code development use a branch. You can use as many branches as you want if you work on multiple issues. Create a "work" branch and move to it:

```
git checkout -b work
```

You can work here, and commit changes as much as you want to. You can push those changes to your github repo by

```
git push origin <branchname>
```

If the branch does not exist in your github repo it will be created. Keeping your github repo up to date also allows us to give you support. In case things don't work we can just clone your repo check out the branch you are workign on and run it to see what's wrong.

You can pull in changes to your work branch from your master branch. To go to your work branch use

```
git checkout work
```

and then merge the changes from the master branch:

```
git merge master
```
