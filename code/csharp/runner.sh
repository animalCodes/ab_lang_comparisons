#!/usr/bin/env bash

# Runner for all C# programs.

# Check dotnet command exists
if ! type dotnet 1>/dev/null 2>&1; then
  echo "dotnet CLI not found, please install to run."
  exit
fi

# CD into the directory this script is in
cd `dirname $BASH_SOURCE`

# If the user didn't specify a program to run, give them a hint + the currently existing implementations.
if [[ ! $1 ]]; then
  echo "Usage: runner.sh {program name} {program arguments}"
  # Automagically generate a list of valid program names
  echo -n "Valid program names: " && ls -I *.*
  exit
fi

# Check specified directory exists, if it does CD into it.
if [ -d $1 ]; then cd $1
else
  echo "\"$1\" doesn't exist. (Hint: running this script without arguments will give you a list of valid program names)"
  exit
fi

# Make copy of all arguments passed to script and delete first item (name of program)
ARGS=("$@")
unset ARGS[0]

# Ensure that .csproj and Program.cs files exist before trying to run program
if [ -f "$1.csproj" ] && [ -f "Program.cs" ]; then
  echo "Running."
  dotnet run ${ARGS[*]}
else
  echo "No .csproj/Program.cs, exiting."
  exit
fi
