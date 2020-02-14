#!/bin/bash

echo start && echo multipleCommands && echo tests
ls -a; echo hello && mkdir test || echo world; git status
ls; rm -rf test || git status
ls -a; echo hello; mkdir test
ls; rm -rf test; echo delete test
echo final ; echo multiple command && echo test
exit # this should exit
