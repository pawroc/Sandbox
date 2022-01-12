#!/bin/bash

(cd c_lib && make clean && make)
cmake -S . -B build
cmake --build build