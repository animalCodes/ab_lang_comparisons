#!/usr/bin/env bash

# Runner for all Ruby programs.

# Check ruby command exists
if ! type ruby > /dev/null; then
  echo "Ruby CLI not found, please install to run."
  exit;
fi

# CD into the directory this script is in
cd `dirname $BASH_SOURCE`

# Get name of program from user
if [[ ! $1 ]]; then
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

if [ -f "script.rb" ]; then
  ruby script.rb ${ARGS[*]}
else echo "No script.rb, exiting."; fi
