#!/usr/bin/env bash

# Runner for all C++ programs.

# Check g++ command exists
if ! type g++ > /dev/null; then
  echo "g++/gcc not found, please install to run."
  exit;
fi

# CD into the directory this script is in
cd `dirname $BASH_SOURCE`

# If user DIDN'T specify a program name on run
if [[ ! $1 ]]; then
  # Get name of program from user, eg "hello_world"
  echo "Enter name of program to run:"
  read NAME
else NAME=$1; fi

# Check specified directory exists, if it does CD into it.
if [ -d $NAME ]; then cd $NAME
else
  echo "\"$NAME\" doesn't exist. (Hint: the 'name of program' is the name of the folder containing said program."
  exit;
fi

# Check main.cpp exists before compiling
if [ -f "main.cpp" ]; then
  echo "Compiling.."
  # Create output folders as needed
  if [ ! -d "../out" ]; then mkdir ../out; fi
  if [ ! -d "../out/$NAME" ]; then mkdir ../out/$NAME; fi
  if [ ! -f "../out/$NAME/main.out" ]; then touch ../out/$NAME/main.out; fi
  g++ main.cpp -o ../out/$NAME/main.out
  echo "Running."
  ../out/$NAME/main.out $2
else
  echo "No main.cpp file found, exiting"
  exit;
fi
