#!/usr/bin/env bash

# Runner for all Kotlin programs.

# Check kotlinc command exists
if ! type kotlinc > /dev/null; then
  echo "Kotlinc not found, please install to run."
  exit;
fi

# This CD's into the directory this script is in, I'm not going to pretend to understand how.
cd "${BASH_SOURCE%/*}"

# Get name of program from user, eg "hello_world"
echo "Enter name of program to run:"
read NAME

# Check specified directory exists, if it does CD into it.
if [ -d $NAME ]; then
  cd $NAME
else
  echo "\"$NAME\" doesn't exist. (Hint: the 'name of program' is the name of the folder containing said program."
  exit;
fi

# Check src/ exists
if [ -d "src" ]; then
  # Compile and run
  echo "Compiling, give it a few seconds."
  kotlinc -include-runtime -d ../out/$NAME.jar src/*
  echo "Done, running."
  java -jar ../out/$NAME.jar
else
  echo "No src folder found, exiting"
  exit;
fi