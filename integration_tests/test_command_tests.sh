#!/bin/sh

test;

test -e rshell || echo “rshell executable missing, check submission instruction section of the specifications”
test -e test || echo “test executable missing, check submission instruction section of the specifications”
test -e names.txt || echo “names.txt file missing, check submission instruction section of the specifications”
test -d unit_tests || echo “unit_tests/ directory missing, check submission instruction section of the specifications”
test -d integration_tests || echo “integration_tests/ directory missing, check submission instruction section of the specifications”

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
test -e test/file/path && echo “path exists” && ls; #one more comment
test -e src && echo “path exists” || ls;

[ -e src ] && echo “path exists” || ls;
[ -d test/file/path ] && echo “path exists”;
[ names.txt ];
[ -e names.txt ];
[ -e test/file/path ];
[ -f test/file/path ];
[ -d test/file/path ];
[ -f src/Executor.cpp ] && echo "hello";
[ -d images ] || echo "world";
[ -f images ] || echo "world";
[ -f src/Executor.cpp ] && echo "hello"; #test with a comment
[ -e test/file/path ] && echo “path exists”; #another comment
[ -e test/file/path ] && (echo “path exists” && ls); #one more comment
[ -e src ] && (echo “path exists” || ls);

echo "end of test"

exit
