#!/usr/bin/env bash

# Runner for all Ruby programs.

# Check ruby command exists
if ! type ruby > /dev/null; then
  echo "Ruby CLI not found, please install to run."
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

# Check script.rb exists
if [ -f "script.rb" ]; then
  ruby script.rb
else
  echo "No script.rb, running random .rb file.."
  ruby *.rb
fi