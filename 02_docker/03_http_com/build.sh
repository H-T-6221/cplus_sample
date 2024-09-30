#!/bin/bash

if [ -d build ]; then
    rm -rf build
fi

mkdir build
cd build

cmake ..
make
cd -

if [ -d module ]; then
    rm -rf module
fi

mkdir module
cp -p build/client/client module
cp -p build/server/server module
