#!/usr/bin/env bash
set -e

cores=$(grep -c processor /proc/cpuinfo)

mkdir -p cmake-build-debug
pushd cmake-build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ../src
make -j$cores
echo
echo "Success:"
file iben

popd
