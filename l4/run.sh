#!/bin/sh
set -e
cmake -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake -S . -B bin
cd bin && make && ./cgmain && cd ..