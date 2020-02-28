#!/bin/sh

echo start singleCommand tests
ls
mkdir tests
ls
rm -rf tests
git status
touch newFile
ls
rm -rf newFile
git help
git clone https://github.com/jackdclark/five.git
ls
rm -rf five
echo final singleCommand test
exit # echo "did it exit"
