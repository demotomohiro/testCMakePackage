# testCMakePackage
Sample CMake code to make a library project so that other project can link it.

testCMake directory contains sample library project "testlib".
testlib project exports testComp, testComp2 and testComp3dep2 library targets.
testComp3dep2 require testComp2.

testCMakeUser contains sample project which uses testlib.

## Requirements
C++ compiler
CMake 3.0 or newer version

## How to build
```console
$ git clone https://github.com/demotomohiro/testCMakePackage.git
```
Build testlib project and install.
CMAKE_INSTALL_PREFIX specifies install directory.
```console
$ mkdir testCMake-build
$ cd testCMake-build
$ cmake -DCMAKE_INSTALL_PREFIX=/path/to/install/directory ../testCMakePackage/testCMake
$ make install
$ cd ..
```

Build testCMakeUser project.
CMAKE_PREFIX_PATH specifies directories to be searched by the find_package() command.
It must contain the directory specified by above CMAKE_INSTALL_PREFIX variable.
```console
$ mkdir testCMakeUser-build
$ cd testCMakeUser-build
$ cmake -DCMAKE_PREFIX_PATH=/path/to/install/directory ../testCMakePackage/testCMakeUser
$ make
```

This software is released under the MIT License, see LICENSE.
