# Collection of functions used in each runner.sh script.

# Print script usage and directories in cwd, exit 1.
function echo_dirs_and_exit
{
  echo Usage: runner.sh {program name} {program arguments} 1>&2
  echo -n "Valid program names: " 1>&2
  ls -w 0 -I *.* -I out 1>&2
  exit 1
}

# If $1 exists, cd into it, else print error and exit 1.
function cd_or_err
{
  if [ -d $1 ]; then cd $1
  else
    echo \"$1\" doesn\'t exist. \(Hint: running this script without arguments will give you a list of valid program names\) 1>&2
    exit 1
  fi
}
