cmake_minimum_required(VERSION 2.8.12)
project(cmake-googletest-project)
include(ExternalProject)

# External projects
ExternalProject_Add(
    googletest
    DOWNLOAD_DIR "googletest/src"
    GIT_REPOSITORY https://github.com/google/googletest.git
    TIMEOUT 10
    LOG_DOWNLOAD ON
    # Disable all other steps
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    PREFIX "googletest"
)

# Build gtest from existing sources
ExternalProject_Add(
    gtest
    DOWNLOAD_COMMAND "" # No download required
    SOURCE_DIR "googletest/src/googletest/googletest" # Use specific source dir
    PREFIX "googletest" # But use prefix for compute other dirs
    INSTALL_COMMAND ""
    LOG_CONFIGURE ON
    LOG_BUILD ON
    BINARY_DIR "googletest/gtest-build"
)

# gtest should be built after being downloaded
add_dependencies(gtest googletest)

# Build gmock from existing sources
ExternalProject_Add(
    gmock
    DOWNLOAD_COMMAND "" # No download required
    SOURCE_DIR "googletest/src/googletest/googlemock" # Use specific source dir
    PREFIX "googletest" # But use prefix for compute other dirs
    INSTALL_COMMAND ""
    LOG_CONFIGURE ON
    LOG_BUILD ON
    BINARY_DIR "googletest/gmock-build"
)

# gmock should be built after being downloaded
add_dependencies(gmock googletest)


###################################
# Build the library
#
###################################

include_directories(include)
file(GLOB SOURCES "src/*.cxx")
add_library(hello ${SOURCES})

###################################
# Build test stuff
###################################

enable_testing()
add_subdirectory(test)








