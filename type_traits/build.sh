#!/bin/bash

mkdir build
(cd build && g++ ../main.cpp -I .. -o test)