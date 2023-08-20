#!/usr/bin/env bash

# Runner for all C programs.

# Check clang command exists
if ! type clang > /dev/null; then
  echo "clang compiler not found, please install to run."
  exit;
fi

# CD into the directory this script is in
cd `dirname ${BASH_SOURCE}`

# If user DIDN'T specify a program to run on start
if [[ ! $1 ]]; then
  # Get name of program from user
  echo "Enter name of program to run:"
  read NAME
# Otherwise use specified name
else NAME=$1; fi

# Check specified directory exists, if it does CD into it.
if [ -d $NAME ]; then cd $NAME
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
  # Compile and run w/ argument.
  clang main.c -o ../out/$NAME/main.out
  ../out/$NAME/main.out $2
else
  echo "No main.c, exiting."
  exit;
fi
