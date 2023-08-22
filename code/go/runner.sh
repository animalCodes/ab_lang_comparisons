#!/usr/bin/env bash

# Runner for all Go programs.

# Check Go command exists
if ! type go 1>/dev/null 2>&1; then
  echo "go CLI not found, please install to run."
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
  echo "\"$1\" doesn't exist. (Hint: run this script without any arguments to get a list of valid programs)"
  exit
fi

# Make copy of all arguments passed to script and delete first item (name of program)
ARGS=("$@")
unset ARGS[0]

# Check atleast a main.go file exists before attempting to run program
if [ -f "main.go" ]; then
  go run main.go ${ARGS[*]}
else
  echo "No main.go, exiting."
  exit
fi
