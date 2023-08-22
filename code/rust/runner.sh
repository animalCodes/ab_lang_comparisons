#!/usr/bin/env bash

# Runner for all Rust programs.

# Check cargo command exists 
if type cargo 1>/dev/null 2>&1; then
  echo "Cargo found, using."
  USECARGO=$(true)
# Check rustc command exists
elif type rustc 1>/dev/null 2>&1; then
  echo "Cargo not found, using rustc instead."
else 
  echo "Neither rustc nor Cargo were found, please install to run."
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
if [ -d $1 ]; then cd $1;
else
  echo "\"$1\" doesn't exist. (Hint: running this script without arguments will give you a list of valid program names)"
  exit
fi

# Make copy of all arguments passed to script and delete first item (name of program)
ARGS=("$@")
unset ARGS[0]

# Use Cargo if it is available, otherwise use rustc directly
if [ $USECARGO ]; then
  cargo run --target-dir ../out/$1 -- ${ARGS[*]}
else
  rustc --out-dir ../out/$1 src/*
  ../out/$1/main ${ARGS[*]}
fi
