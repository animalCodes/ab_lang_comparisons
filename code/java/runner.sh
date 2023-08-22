#!/usr/bin/env bash

# Runner for all Java programs.

# Check javac command exists
if ! type javac 1>/dev/null 2>&1; then
  echo "Javac not found, please install to run."
  exit;
fi

# CD into the directory this script is in
cd `dirname $BASH_SOURCE`

if [[ ! $1 ]]; then
  # Get name of program from user
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

# For whatever reason Java doesn't like '_'s in package names, so we have to remove them using this weirdness.
PACKAGE_NAME=$(echo "${NAME//_}")

# Make copy of all arguments passed to script and delete first item (name of program)
ARGS=("$@")
unset ARGS[0]

if [ -d "src" ]; then
  # Compile and run
  echo "Compiling, give it a couple seconds."
  javac -d ../out/$NAME src/comparisons/java/$PACKAGE_NAME/*
  echo "Done, running."
  cd ../out/$NAME
  java comparisons/java/$PACKAGE_NAME/Main ${ARGS[*]}
else
  echo "No src folder found, exiting"
  exit;
fi
