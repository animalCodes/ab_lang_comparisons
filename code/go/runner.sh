#!/usr/bin/env bash

# Runner for all Go programs.

if ! type go 1>/dev/null 2>&1; then
  echo go CLI not found, please install to run. 1>&2
  exit 1
fi

cd `dirname $BASH_SOURCE`

. ../scripts/common.sh

if [[ ! $1 ]]; then echo_dirs_and_exit; fi

cd_or_err $1

ARGS=("$@")
unset ARGS[0]

if [ -f "main.go" ]; then
  go build -o ../out/$1/main.out ./
  ../out/$1/main.out ${ARGS[*]}
  exit
else
  echo No main.go, exiting. 1>&2
  exit 1
fi
