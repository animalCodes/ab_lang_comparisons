#!/usr/bin/env bash

# Runner for all C# programs.

# Check dotnet command exists
if ! type dotnet > /dev/null; then
  echo "dotnet CLI not found, please install to run."
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

# Check .csproj and Program.cs files both exist
if [ -f "$NAME.csproj" ] && [ -f "Program.cs" ]; then
  dotnet run $NAME
else
  echo "No .csproj or Program.cs, exiting."
  exit;
fi