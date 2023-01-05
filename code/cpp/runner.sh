#!/usr/bin/env bash

# Runner for all C++ programs.

# Check g++ command exists
if ! type g++ > /dev/null; then
  echo "g++/gcc not found, please install to run."
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

# Check main.cpp exists before compiling
if [ -f "main.cpp" ]; then
  echo "Compiling.."
  g++ main.cpp
  # For some reason specifying an out file for g++ was causing the whole process to break, so just do it manually.
  echo "Moving .out file and running."
  mv a.out ../out/$NAME/
  ../out/$NAME/a.out
else
  echo "No main.cpp file found, exiting"
  exit;
fi
