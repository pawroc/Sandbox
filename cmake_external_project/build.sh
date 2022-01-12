#!/bin/bash

cmake -S external_dir -B app/build/deps/libFoo
cmake --build app/build/deps/libFoo
cmake --install app/build/deps/libFoo --prefix app/build/ext_dir
cmake -S app -B app/build
cmake --build app/build

echo "Testing by running executable:"
./app/build/main