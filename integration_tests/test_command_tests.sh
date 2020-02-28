#!/bin/bash

test;
test names.txt;
test -e names.txt;
test -e test/file/path;
test -f test/file/path;
test -d test/file/path;
test -f src/Executor.cpp && echo "hello";
test -d images || echo "world";
test -f images || echo "world";
test -f src/Executor.cpp && echo "hello"; #test with a comment
test -e test/file/path && echo “path exists”; #another comment
exit
