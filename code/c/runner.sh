#!/usr/bin/env bash

# Runner for all C programs.

# Check C command exists
if ! type clang > /dev/null; then
  echo "clang compiler not found, please install to run."
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

# Check main.go file exists
if [ -f "main.c" ]; then
  # Create output folders/file as needed.
  if [ ! -d "../out" ]; then mkdir ../out; fi
  if [ ! -d "../out/$NAME/" ]; then mkdir ../out/$NAME; fi
  if [ ! -f "../out/$NAME/main.out" ]; then touch ../out/$NAME/main.out; fi
  # Compile and run
  clang main.c -o ../out/$NAME/main.out
  ../out/$NAME/main.out
else
  echo "No main.c, exiting."
  exit;
fi
