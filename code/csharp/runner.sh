#!/usr/bin/env bash

# Runner for all C# programs.

if ! type dotnet 1>/dev/null 2>&1; then
  echo dotnet CLI not found, please install to run. 1>&2
  exit 1
fi

cd `dirname $BASH_SOURCE`

. ../scripts/common.sh

if [[ ! $1 ]]; then echo_dirs_and_exit; fi

cd_or_err $1

ARGS=("$@")
unset ARGS[0]

if [ -f "$1.csproj" ] && [ -f "Program.cs" ]; then
  dotnet clean 1>/dev/null
  # Error output is also sent to stdout for some reason, so keep it here.
  dotnet build
  echo
  # TODO deal with different .NET versions?
  ./bin/Debug/net7.0/$1 ${ARGS[*]}
  exit
else
  echo No $1.csproj or Program.cs file, exiting. 1>&2
  exit 1
fi
