#!/usr/bin/env bash

# Runner for all Kotlin programs.

if ! type kotlinc 1>/dev/null 2>&1; then
  echo kotlinc not found, please install to run. 1>&2
  exit 1
fi

if ! type java 1>/dev/null 2>&1; then
  echo java not found, please install to run. 1>&2
  exit 1
fi

cd `dirname $BASH_SOURCE`

. ../scripts/common.sh

if [[ ! $1 ]]; then echo_dirs_and_exit; fi

cd_or_err $1

ARGS=("$@")
unset ARGS[0]

if [ -d "src" ]; then
  kotlinc -include-runtime -d ../out/$1.jar src/*
  java -jar ../out/$1.jar ${ARGS[*]}
  exit
else
  echo No src folder found, exiting 1>&2
  exit 1
fi
