#!/usr/bin/env bash

# Runner for all Rust programs.

# Check cargo command exists
if ! type cargo > /dev/null; then
  echo "cargo not found, please install to run."
  exit;
fi

# This CD's into the directory this script is in, I'm not going to pretend to understand how.
cd "${BASH_SOURCE%/*}"

# Get name of program from user, eg "hello_world"
if [[ ! $1 ]]; then
  echo "Enter name of program to run:"
  read NAME
else NAME=$1; fi

# Check specified directory exists, if it does CD into it.
if [ -d $NAME ]; then cd $NAME
else
  echo "\"$NAME\" doesn't exist. (Hint: the 'name of program' is the name of the folder containing said program."
  exit;
fi

# Check src/ exists before running
if [ -d "src" ]; then
  cargo run --target-dir ../out/$NAME -- $2
else echo "No src folder found, exiting"; fi
