#!/usr/bin/env bash

# Runner for all Node.js programs.

if ! type node 1>/dev/null 2>&1; then 
  echo node command not found, please install to run. 1>&2
  exit 1
fi

cd `dirname $BASH_SOURCE`

. ../scripts/common.sh

if [[ ! $1 ]]; then echo_dirs_and_exit; fi

cd_or_err $1

ARGS=("$@")
unset ARGS[0]

if [ -f "app.js" ]; then
  node app.js ${ARGS[*]}
  exit
else 
  echo No app.js, exiting. 1>&2
  exit 1
fi
