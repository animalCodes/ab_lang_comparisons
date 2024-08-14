#!/usr/bin/env bash

# Runner for all Java programs.

# Check javac command exists
if ! type javac 1>/dev/null 2>&1; then
  echo Javac not found, please install to run. 1>&2
  exit 1
fi

cd `dirname $BASH_SOURCE`

. ../scripts/common.sh

if [[ ! $1 ]]; then echo_dirs_and_exit; fi

cd_or_err $1

# For whatever reason Java doesn't like '_'s in package names, so we have to remove them using this weirdness.
PACKAGE_NAME=$(echo "${1//_}")

ARGS=("$@")
unset ARGS[0]

if [ -d "src" ]; then
  javac -d ../out/$1 src/comparisons/java/$PACKAGE_NAME/*
  cd ../out/$1
  java comparisons/java/$PACKAGE_NAME/Main ${ARGS[*]}
  exit
else
  echo No src folder found, exiting 1>&2
  exit 1
fi
