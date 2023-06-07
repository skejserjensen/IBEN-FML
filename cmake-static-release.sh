#!/usr/bin/env bash
set -e

BUILD=build-release
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_BUILD_STATIC=ON -B "$BUILD" src
cmake --build "$BUILD"
echo
echo "Success:"
file "$BUILD/iben"
