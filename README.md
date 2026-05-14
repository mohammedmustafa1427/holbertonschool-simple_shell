# Simple Shell

## Description

A simple UNIX command line interpreter written in C.
This shell can read and execute commands in both interactive and non-interactive mode.

## Requirements

* Ubuntu 20.04 LTS
* gcc compiler

## Compilation

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Usage

### Interactive mode

$ ./hsh
($) /bin/ls
hsh main.c shell.c shell.h
($)

### Non-interactive mode

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c shell.h

## Features

* Display a prompt and wait for user input
* Execute commands
* Handle errors
* Handle end of file condition (Ctrl+D)

## Authors

* Noura Alotibi - ms.nora1424@gmail.com
* Mohammed Mustafam
