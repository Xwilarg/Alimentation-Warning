#!/bin/sh
mkdir -p build
cd build
set -e
cmake ..
cmake --build . --config RELEASE
cp Release/AlimentationWarning.exe ..