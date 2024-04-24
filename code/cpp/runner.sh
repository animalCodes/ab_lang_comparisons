#!/usr/bin/env bash

# Runner for all C++ programs.

# Choose compiler
if type g++ 1>/dev/null 2>&1; then
  CMD=g++
elif type clang++ 1>/dev/null 2>&1; then
  CMD=clang++
else
  echo "Neither g++ or clang are available, please install one to run."
  exit 1
fi

echo "$CMD found, using"

# CD into the directory this script is in
cd `dirname $BASH_SOURCE`

# If the user didn't specify a program to run, give them a hint + the currently existing implementations.
if [[ ! $1 ]]; then
  echo "Usage: runner.sh {program name} {program arguments}"
  # Automagically generate a list of valid program names
  echo -n "Valid program names: " && ls -I *.*
  exit 1
fi

# Check specified directory exists, if it does CD into it.
if [ -d $1 ]; then cd $1
else
  echo "\"$1\" doesn't exist. (Hint: running this script without arguments will give you a list of valid program names)"
  exit 1
fi

# Make copy of all arguments passed to script and delete first item (name of program)
ARGS=("$@")
unset ARGS[0]

# Check a directory exists before attempting to compile program
if [ -d "src" ]; then
  echo "Compiling.."
  mkdir -p ../out/$1/
  $CMD -o ../out/$1/main.out src/*
  echo "Running."
  ../out/$1/main.out ${ARGS[*]}
  exit
else 
  echo "No src directory found, exiting"
  exit 1
fi
