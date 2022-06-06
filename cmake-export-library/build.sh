#!/bin/bash

cmake -DCMAKE_BUILD_TYPE=Release -B build/release
cmake -DCMAKE_BUILD_TYPE=Debug -B build/debug

cmake --build build/release
cmake --build build/debug

# These is redundant if CPack is used
cmake --install build/release --prefix /tmp/install
cmake --install build/debug --prefix /tmp/install-d

# CPack will create a package and installed script.
# In order to install package one should run the generated script
# with --prefix=<install_dir>
(cp cpack-scripts/MultiCPackConfig.cmake build && cd build && cpack --config MultiCPackConfig.cmake)