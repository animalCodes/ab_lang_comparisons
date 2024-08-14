#!/usr/bin/env bash

# Runner for all C++ programs.

if type g++ 1>/dev/null 2>&1; then
  CMD=g++
elif type clang++ 1>/dev/null 2>&1; then
  CMD=clang++
else
  echo Neither g++ or clang++ are available, please install one to run. 1>&2
  exit 1
fi

cd `dirname $BASH_SOURCE`

. ../scripts/common.sh

if [[ ! $1 ]]; then echo_dirs_and_exit; fi

cd_or_err $1

ARGS=("$@")
unset ARGS[0]

if [ -d "src" ]; then
  mkdir -p ../out/$1/
  $CMD -o ../out/$1/main.out src/*
  ../out/$1/main.out ${ARGS[*]}
  exit
else 
  echo No src directory found, exiting 1>&2
  exit 1
fi
