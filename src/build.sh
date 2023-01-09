#!/bin/bash

CC="g++"
SRC="main.cc Model/ConsoleHelper/MazeMatrix/mazematrix.cc"
EXE="maze.exe"

$CC $SRC -o $EXE
./$EXE
rm ./$EXE