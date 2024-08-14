#!/usr/bin/env bash

# Runner for all Ruby programs.

if ! type ruby 1>/dev/null 2>&1; then
  echo "Ruby CLI not found, please install to run."
  exit 1
fi

cd `dirname $BASH_SOURCE`

. ../scripts/common.sh

if [[ ! $1 ]]; then echo_dirs_and_exit; fi

cd_or_err $1

ARGS=("$@")
unset ARGS[0]

if [ -f "script.rb" ]; then
  ruby script.rb ${ARGS[*]}
  exit
else
  echo "No script.rb, exiting."
  exit 1
fi
