#!/bin/bash

CC="g++"
SRC="main.cc"
EXE="maze.exe"

$CC $SRC -o $EXE
./$EXE
rm ./$EXE