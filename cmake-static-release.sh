#!/usr/bin/env bash
set -e

cores=$(grep -c processor /proc/cpuinfo)

mkdir -p cmake-build-release
pushd cmake-build-release
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_BUILD_STATIC=1 ../src
make -j$cores
echo
echo "Success:"
file iben
popd

