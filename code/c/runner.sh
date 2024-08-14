#!/usr/bin/env bash

# Runner for all C programs.

# We could probably just use `cc`, but this feels less "magic".
if type gcc 1>/dev/null 2>&1; then
  CMD=gcc
elif type clang 1>/dev/null 2>&1; then
  CMD=clang
elif type tcc 1>/dev/null 2>&1; then
  CMD=tcc
else
  echo "No compiler found, please install one of GCC, Clang or TCC to use this script."
  exit 1
fi

echo "$CMD found, using."

cd `dirname ${BASH_SOURCE}`

. ../scripts/common.sh

if [[ ! $1 ]]; then echo_dirs_and_exit; fi

cd_or_err $1

ARGS=("$@")
unset ARGS[0]

if [ -f "src/main.c" ]; then
  mkdir -p ../out/$1
  $CMD src/* -o ../out/$1/main.out -lm
  ../out/$1/main.out ${ARGS[*]}
  exit
else
  echo "No main.c, exiting."
  exit 1
fi
