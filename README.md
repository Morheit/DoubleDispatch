[![Build Status](https://travis-ci.org/Morheit/DoubleDispatch.svg?branch=master)](https://travis-ci.org/Morheit/DoubleDispatch)

# DoubleDispatch #

## Problem ##

There is an interface with some count of the implementations. Need to use these implementations through the interface with 
one limitation - without [RTTI](https://en.wikibooks.org/wiki/C%2B%2B_Programming/RTTI) mechanism in the "release".

In this repository considered a three ways of solving such case using `static_cast` and the
[Double Dispatch](https://en.wikipedia.org/wiki/Double_dispatch) pattern in particular.

## Platform ##

* Linux
* macOS

## Requirements ##

* GNU-compatible Make
* POSIX-standard shell
* A C++11-standard-compliant compiler

## Build ##

### Build commands ###

By default used clang compiler and debug mode.

Run in project root to build debug version with clang

`make` or `make clang-debug`

To build release version with gcc run the following command

`make gcc-release`

## Run ##

Run from build directory

`ctest`

or

`ctest AllTests`
