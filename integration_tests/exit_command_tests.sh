#!/bin/bash

false || exit
ls || exit
lss && exit
echo time && time && exit
mkdir test; rm -rf tests; exit
ls -a; echo hello && mkdir test || echo world; git status; exit
ls -a; echo hello; mkdir test; exit
exit || echo this line
echo final exit command test && exit
exit # echo this should exit
