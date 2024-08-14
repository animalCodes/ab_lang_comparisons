#!/usr/bin/env bash

# Runner for all Kotlin programs.

if ! type kotlinc 1>/dev/null 2>&1; then
  echo "Kotlinc not found, please install to run."
  exit 1
fi

cd `dirname $BASH_SOURCE`

. ../scripts/common.sh

if [[ ! $1 ]]; then echo_dirs_and_exit; fi

cd_or_err $1

ARGS=("$@")
unset ARGS[0]

if [ -d "src" ]; then
  echo "Compiling, give it a few seconds."
  kotlinc -include-runtime -d ../out/$1.jar src/*
  echo "Done, running."
  java -jar ../out/$1.jar ${ARGS[*]}
  exit
else
  echo "No src folder found, exiting"
  exit 1
fi
