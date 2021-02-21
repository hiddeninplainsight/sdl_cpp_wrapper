#!/usr/bin/env bash

cd `dirname $0`
builddir=`pwd`/build
rm -rf $builddir
mkdir -p $builddir
cd build

build_opts=" \
    -D CMAKE_DISABLE_FIND_PACKAGE_ZLIB=TRUE \
    -D CMAKE_DISABLE_FIND_PACKAGE_BZip2=TRUE \
    -D CMAKE_DISABLE_FIND_PACKAGE_PNG=TRUE \
    -D CMAKE_DISABLE_FIND_PACKAGE_HarfBuzz=TRUE \
    -D CMAKE_DISABLE_FIND_PACKAGE_BrotliDec=TRUE \
    -UBUILD_SHARED_LIBS \
    -DCMAKE_INSTALL_PREFIX=$builddir/out"

cmake -DCMAKE_BUILD_TYPE=Release \
    $build_opts \
    ../freetype

make install
