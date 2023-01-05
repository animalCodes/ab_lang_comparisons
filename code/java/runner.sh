#!/usr/bin/env bash

# Runner for all Java programs.

# Check javac command exists
if ! type javac > /dev/null; then
  echo "Javac not found, please install to run."
  exit;
fi

# This CD's into the directory this script is in, I'm not going to pretend to understand how.
cd "${BASH_SOURCE%/*}"

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

# For whatever reason Java doesn't like '_'s in package names, so we have to remove them using some weirdness.
PACKAGE_NAME=$(echo "${NAME//_}")

# Check src/ exists
if [ -d "src" ]; then
  # Compile and run
  echo "Compiling, give it a couple seconds."
  javac -d ../out/$NAME src/comparisons/java/$PACKAGE_NAME/*
  echo "Done, running."
  cd ../out/$NAME
  java comparisons/java/$PACKAGE_NAME/Main $2
else
  echo "No src folder found, exiting"
  exit;
fi
