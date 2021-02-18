#!/usr/bin/env bash

cd `dirname $0`
builddir=`pwd`/build
rm -rf $builddir
mkdir -p $builddir
cd build

build_opts="-DWITH_ZLIB=0 \
    -DWITH_BZip2=0 \
    -DWITH_PNG=0 \
    -DWITH_HarfBuzz=0 \
    -UBUILD_SHARED_LIBS \
    -DCMAKE_INSTALL_PREFIX=$builddir/out"

cmake -DCMAKE_BUILD_TYPE=Release \
    $build_opts \
    ../freetype

make install
