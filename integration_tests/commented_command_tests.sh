#!/bin/bash

echo start commented tests #echo but not this
ls -a; echo hello && mkdir test || echo world; git status # echo this is from the readme
ls && echo hello #echo world
mkdir commentTest || echo add commentTest #echo don't echo
rm -rf commentTest && echo removed commentTest # echo should've deleted dir
lol || echo lol #echo the word lol
ls  #echo list directories
echo hello; echo fellow; echo students #should print 3 words
echo cant; false || echo word #echo feels bad
echo final commented test; false && echo test #echo last test
exit # echo "did it exit"
