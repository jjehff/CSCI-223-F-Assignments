#!/bin/bash

gcc -c main.c
gcc -c add.c
gcc -c sub.c
gcc main.o add.o sub.o

chmod 750 build.sh
