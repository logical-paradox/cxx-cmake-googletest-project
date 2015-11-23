#include "gtest/gtest.h"
#include "HelloWorld.h"

TEST(HelloWorldTest, ObjectCreation)
{
    HelloWorld hello;

    hello.say_hello();
}

