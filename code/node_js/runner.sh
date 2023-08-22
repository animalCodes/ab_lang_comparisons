#!/usr/bin/env bash

# Runner for all Node.js programs.

# Check node command exists
if ! type node 1>/dev/null 2>&1; then 
  echo "node command not found, please install to run."
  exit
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
  exit
fi

# Make copy of all arguments passed to script and delete first item (name of program)
ARGS=("$@")
unset ARGS[0]

if [ -f "app.js" ]; then
  node app.js ${ARGS[*]}
else echo "No app.js, exiting."; fi
