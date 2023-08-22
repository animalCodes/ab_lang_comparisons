#!/usr/bin/env bash

# Runner for all C programs.

# Find available compiler(s)
if type gcc 1>/dev/null 2>&1; then
  echo "GCC found, using"
  CMD=gcc
elif type clang >/dev/null; then
  echo "Clang found, using"
  CMD=clang
elif type tcc >/dev/null; then
  echo "TCC found, using"
  CMD=tcc
else
  echo "No compiler found, please install one of GCC, Clang or TCC to use this script."
  exit
fi

# CD into the directory this script is in
cd `dirname ${BASH_SOURCE}`

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

# Check a main.c file exists before attempting to compile/run
if [ -f "src/main.c" ]; then
  # Create output folders/file as needed.
  if [ ! -d "../out" ]; then mkdir ../out; fi
  if [ ! -d "../out/$1/" ]; then mkdir ../out/$1; fi
  if [ ! -f "../out/$1/main.out" ]; then touch ../out/$1/main.out; fi
  # Compile and run w/ argument.
  $CMD src/* -o ../out/$1/main.out
  ../out/$1/main.out ${ARGS[*]}
else
  echo "No main.c, exiting."
  exit
fi
