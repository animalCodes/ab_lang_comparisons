#!/usr/bin/env bash

# Runner for all Kotlin programs.

# Check kotlinc command exists
if ! type kotlinc 1>/dev/null 2>&1; then
  echo "Kotlinc not found, please install to run."
  exit;
fi

# CD into the directory this script is in
cd `dirname $BASH_SOURCE`

if [[ ! $1 ]]; then
  # Get name of program from user, eg "hello_world"
  echo "Enter name of program to run:"
  read NAME
else NAME=$1; fi

# Check specified directory exists, if it does CD into it.
if [ -d $NAME ]; then cd $NAME
else
  echo "\"$NAME\" doesn't exist. (Hint: the 'name of program' is the name of the folder containing said program."
  exit;
fi

# Make copy of all arguments passed to script and delete first item (name of program)
ARGS=("$@")
unset ARGS[0]

if [ -d "src" ]; then
  # Compile and run
  echo "Compiling, give it a few seconds."
  kotlinc -include-runtime -d ../out/$NAME.jar src/*
  echo "Done, running."
  java -jar ../out/$NAME.jar ${ARGS[*]}
else
  echo "No src folder found, exiting"
  exit;
fi
