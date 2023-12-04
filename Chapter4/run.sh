#!/bin/bash

if [ ! -d "bin" ]; then
    mkdir -p bin
fi

if [ $# -ne 1 ]; then
    echo "Usage: $0 <source_file>"
    exit 1
elif [ ! -f "$1" ]; then
    echo "The file you provided does not exist!"
    exit 1
fi

filename=$(basename "$1")
exe_file="${filename%.*}"

echo "Compiling $1..."
cc "$1" -o "bin/$exe_file" -lm

if [ $? -eq 0 ]; then
    echo "Compilation successful."
    echo "Running $exe_file..."
    "./bin/$exe_file"

    # Comment this line in case you want to keep the binary files
    rm -f "./bin/$exe_file"
else
    echo "Compilation failed."
fi
