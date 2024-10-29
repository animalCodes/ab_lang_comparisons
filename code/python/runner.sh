#!/usr/bin/env bash

# Runner for all Ruby programs.

if ! type python 1>/dev/null 2>&1; then
  echo Python cli not found, please install to run. 1>&2
  exit 1
fi

cd `dirname $BASH_SOURCE`

. ../scripts/common.sh

if [[ ! $1 ]]; then echo_dirs_and_exit; fi

cd_or_err $1

ARGS=("$@")
unset ARGS[0]

if [ -f "script.py" ]; then
  python script.py ${ARGS[*]}
  exit
else
  echo No script.py, exiting. 1>&2
  exit 1
fi
