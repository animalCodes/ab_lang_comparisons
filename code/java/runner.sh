#!/usr/bin/env bash

# Runner for all Java programs.

# Check javac command exists
if ! type javac 1>/dev/null 2>&1; then
  echo "Javac not found, please install to run."
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

# For whatever reason Java doesn't like '_'s in package names, so we have to remove them using this weirdness.
PACKAGE_NAME=$(echo "${1//_}")

# Make copy of all arguments passed to script and delete first item (name of program)
ARGS=("$@")
unset ARGS[0]

# Check that a src directory exists before trying to compile
if [ -d "src" ]; then
  # Compile and run
  echo "Compiling, give it a couple seconds."
  javac -d ../out/$1 src/comparisons/java/$PACKAGE_NAME/*
  echo "Done, running."
  cd ../out/$1
  java comparisons/java/$PACKAGE_NAME/Main ${ARGS[*]}
  exit
else
  echo "No src folder found, exiting"
  exit 1
fi
