#!/usr/bin/env bash

# Runner for all Kotlin programs.

# Check kotlinc command exists
if ! type kotlinc 1>/dev/null 2>&1; then
  echo "Kotlinc not found, please install to run."
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

# Check a "src" directory exists before attempting to compile
if [ -d "src" ]; then
  echo "Compiling, give it a few seconds."
  kotlinc -include-runtime -d ../out/$1.jar src/*
  echo "Done, running."
  java -jar ../out/$1.jar ${ARGS[*]}
else
  echo "No src folder found, exiting"
  exit
fi
