#!/usr/bin/env zsh


echo $1
if [ $1 = "build" ]; then
    cmake --build build
elif [ $1 = "run" ]; then
    build/paddle_exe
fi