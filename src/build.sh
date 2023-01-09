#!/bin/bash

CC="g++ -std=c++17"
CFLAGS="-Wall -Werror -Wextra"
SRC="main.cc Model/ConsoleHelper/MazeMatrix/mazematrix.cc Model/ConsoleMaze/consolemaze.cc"
EXE="maze.exe"

$CC $CFLAGS $SRC -o $EXE
./$EXE
rm ./$EXE