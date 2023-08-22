#!/usr/bin/env bash

# Runner for all C programs.

# Find available compiler(s)
if type gcc 1>/dev/null 2>&1; then
  echo "GCC found, using"
  CMD=gcc
elif type clang >/dev/null; then
  echo "Clang found, using"
  CMD=clang
elif type tcc >/dev/null; then
  echo "TCC found, using"
  CMD=tcc
else
  echo "No compiler found, please install one of GCC, Clang or TCC to use this script."
  exit
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
  exit
fi

# Make copy of all arguments passed to script and delete first item (name of program)
ARGS=("$@")
unset ARGS[0]

if [ -f "src/main.c" ]; then
  # Create output folders/file as needed.
  if [ ! -d "../out" ]; then mkdir ../out; fi
  if [ ! -d "../out/$NAME/" ]; then mkdir ../out/$NAME; fi
  if [ ! -f "../out/$NAME/main.out" ]; then touch ../out/$NAME/main.out; fi
  # Compile and run w/ argument.
  $CMD src/* -o ../out/$NAME/main.out
  ../out/$NAME/main.out ${ARGS[*]}
else
  echo "No main.c, exiting."
  exit
fi
