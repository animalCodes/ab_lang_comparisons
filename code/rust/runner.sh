#!/usr/bin/env bash

# Runner for all Rust programs.

# Check cargo command exists 
if type cargo > /dev/null; then
  echo "Cargo found, using."
  USECARGO=$(true)
# Check rustc command exists
elif type rustc > /dev/null; then
  echo "Cargo not found, using rustc instead."
else 
  echo "Neither rustc nor Cargo were found, please install to run."
  exit;
fi

# CD into the directory this script is in by utilising the dark arts.
cd "${BASH_SOURCE%/*}"

# Get name of program + arguments from user if not already received.
if [ ! $1 ]; then
  echo "Enter name of program to run + optional argument: "
  read NAME ARG
else 
  NAME=$1
  ARG=$2
fi

# Check specified directory exists, if it does CD into it.
if [ -d $NAME ]; then cd $NAME;
else
  echo "\"$NAME\" doesn't exist."
  echo "Hint: the 'name of program' is the name of the folder containing said program."
  exit;
fi

# Use Cargo, or don't.
if [ $USECARGO ]; then
  cargo run --target-dir ../out/$NAME -- $ARG
else
  rustc --out-dir ../out/$NAME src/*
  ../out/$NAME/main $ARG
fi
