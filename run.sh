#!/bin/sh

set -ex

mkdir -p bins

bin_name=$(echo "$1" | sed 's/\.c//g')

gcc "$1"  -g -o "bins/$bin_name"
#gcc "$1" -o "bins/$bin_name"

export PATH="$PWD/bins;$PATH"

gdbbin() {
  gdb -batch \
  -ex "run" \
  -ex "bt" \
  --args "$@"
}

gdbbin "bins/$bin_name"

