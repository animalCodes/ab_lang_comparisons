#!/usr/bin/env bash

# Runner for all C# programs.

# Check dotnet command exits
if ! type dotnet > /dev/null; then
  echo "dotnet CLI not found, please install to run."
  exit;
fi

# CD into the directory this script is in
cd `dirname $BASH_SOURCE`

# If user hasn't specified a program to run already
if [[ ! $1 ]]; then
  # Prompt them for name of program
  echo "Enter name of program to run:"
  read NAME
else NAME=$1; fi

# Check specified directory exists, if it does CD into it.
if [ -d $NAME ]; then cd $NAME
else
  echo "\"$NAME\" doesn't exist. (Hint: the 'name of program' is the name of the folder containing said program."
  exit;
fi

# Make copy of all arguments passed to script and delete first item (name of program)
ARGS=("$@")
unset ARGS[0]

if [ -f "$NAME.csproj" ] && [ -f "Program.cs" ]; then
  echo "Running."
  dotnet run ${ARGS[*]}
else
  echo "No .csproj/Program.cs, exiting."
  exit;
fi
