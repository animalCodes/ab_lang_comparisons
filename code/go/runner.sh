#!/usr/bin/env bash

# Runner for all Go programs.

# Check Go command exists
if ! type go > /dev/null; then
  echo "go CLI not found, please install to run."
  exit;
fi

# CD into the directory this script is in
cd `dirname $BASH_SOURCE`

# Check if an argument has been passed in, if so assume it's the name of the program to run
if [[ ! $1 ]]; then
  # Get name of program from user, eg "hello_world"
  echo "Enter name of program to run:"
  read NAME
else NAME=$1; fi

# Check specified directory exists, if it does CD into it.
if [ -d $NAME ]; then
  cd $NAME
else
  echo "\"$NAME\" doesn't exist. (Hint: the 'name of program' is the name of the folder containing said program."
  exit;
fi

# Make copy of all arguments passed to script and delete first item (name of program)
ARGS=("$@")
unset ARGS[0]

if [ -f "main.go" ]; then
  go run main.go ${ARGS[*]}
else
  echo "No main.go, exiting."
  exit;
fi
