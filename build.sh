#!/bin/sh

set -xe

clang -Wall -Wextra -o cell cell.c
clang -Wall -Wextra -o gates gates.c

./cell
./gates