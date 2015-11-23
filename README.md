This sample project builds a C++ library with CMake, and includes Google's googletest unit test framework for testing the library.

googltest is cloned from github as part of the build process, so it is not necessary to keep a copy of it in the project repo.

You can build this sample project and run the unit tests by performing the following steps:

1. git clone git@github.com:logical-paradox/cxx-cmake-googletest-project.git
2. cd cxx-cmake-googletest-project/build
3. cmake ..
4. make
5. make test


