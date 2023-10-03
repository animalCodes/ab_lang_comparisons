#!/usr/bin/env bash

# Runner for all C programs.

# Find available compiler(s)
# We could probably just use `cc`, but this feels less "magic".
if type gcc 1>/dev/null 2>&1; then
  CMD=gcc
elif type clang 1>/dev/null 2>&1; then
  CMD=clang
elif type tcc 1>/dev/null 2>&1; then
  CMD=tcc
else
  echo "No compiler found, please install one of GCC, Clang or TCC to use this script."
  exit 1
fi

echo "$CMD found, using."

# CD into the directory this script is in
cd `dirname ${BASH_SOURCE}`

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

# Check a main.c file exists before attempting to compile/run
if [ -f "src/main.c" ]; then
  mkdir -p ../out/$1
  $CMD src/* -o ../out/$1/main.out
  ../out/$1/main.out ${ARGS[*]}
  exit
else
  echo "No main.c, exiting."
  exit 1
fi
