#!/bin/sh

set -xe

clang -Wall -Wextra -o cell cell.c -lm
clang -Wall -Wextra -o gates gates.c -lm

./cell
./gates