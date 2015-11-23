enable_testing()
ExternalProject_Get_Property(gtest source_dir)
ExternalProject_Get_Property(gtest binary_dir)
MESSAGE(STATUS "source_dir: " ${source_dir})
MESSAGE(STATUS "binary_dir: " ${binary_dir})
include_directories(${source_dir}/include)
add_executable(HelloWorldTest "HelloWorldTest.cxx")
find_package(Threads)
target_link_libraries(HelloWorldTest ${CMAKE_BINARY_DIR}/libhello.a ${binary_dir}/libgtest_main.a ${binary_dir}/libgtest.a)
target_link_libraries(HelloWorldTest ${CMAKE_THREAD_LIBS_INIT})
add_dependencies(HelloWorldTest gtest)


add_test(
    NAME HelloWorldTest
    COMMAND HelloWorldTest
)




