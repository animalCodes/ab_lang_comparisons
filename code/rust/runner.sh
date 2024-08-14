#!/usr/bin/env bash

# Runner for all Rust programs.

if type cargo 1>/dev/null 2>&1; then
  echo Cargo found, using. 1>&2
  USECARGO=$(true)
elif type rustc 1>/dev/null 2>&1; then
  echo Cargo not found, using rustc instead. 1>&2
else
  echo Neither rustc nor Cargo were found, please install to run. 1>&2
  exit 1
fi

cd `dirname $BASH_SOURCE`

. ../scripts/common.sh

if [[ ! $1 ]]; then echo_dirs_and_exit; fi

cd_or_err $1

ARGS=("$@")
unset ARGS[0]

if [ -d "src" ]; then
  if [ $USECARGO ]; then
    cargo build --target-dir ../out/$1
  else
    rustc --out-dir ../out/$1 src/*
  fi
    ../out/$1/main ${ARGS[*]}
    exit
else
  echo No src directory, exiting. 1>&2
  exit 1
fi
