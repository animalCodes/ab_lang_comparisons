#!/usr/bin/env bash

# Runner for all C++ programs.

# Check g++ command exists
if ! type g++ 1>/dev/null 2>&1; then
  echo "g++/gcc not found, please install to run."
  exit
fi

# CD into the directory this script is in
cd `dirname $BASH_SOURCE`

# If the user didn't specify a program to run, give them a hint + the currently existing implementations.
if [[ ! $1 ]]; then
  echo "Usage: runner.sh {program name} {program arguments}"
  # Automagically generate a list of valid program names
  echo -n "Valid program names: " && ls -I *.*
  exit
fi

# Check specified directory exists, if it does CD into it.
if [ -d $1 ]; then cd $1
else
  echo "\"$1\" doesn't exist. (Hint: running this script without arguments will give you a list of valid program names)"
  exit
fi

# Make copy of all arguments passed to script and delete first item (name of program)
ARGS=("$@")
unset ARGS[0]

# Check a main.cpp file exists before attempting to compile program
if [ -f "main.cpp" ]; then
  echo "Compiling.."
  # Create output folders as needed
  if [ ! -d "../out" ]; then mkdir ../out; fi
  if [ ! -d "../out/$1" ]; then mkdir ../out/$1; fi
  if [ ! -f "../out/$1/main.out" ]; then touch ../out/$1/main.out; fi
  g++ main.cpp -o ../out/$1/main.out
  echo "Running."
  ../out/$1/main.out ${ARGS[*]}
else
  echo "No main.cpp file found, exiting"
  exit
fi
