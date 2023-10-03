#!/usr/bin/env bash

# Runner for all Ruby programs.

# Check ruby command exists
if ! type ruby 1>/dev/null 2>&1; then
  echo "Ruby CLI not found, please install to run."
  exit 1
fi

# CD into the directory this script is in
cd `dirname $BASH_SOURCE`

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

# Check a script.rb file exists before running
if [ -f "script.rb" ]; then
  ruby script.rb ${ARGS[*]}
  exit
else 
  echo "No script.rb, exiting."
  exit 1
fi
