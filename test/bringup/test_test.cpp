#include <cstdio>
#include "gtest/gtest.h"

/*-------------------------------------------------
A very simple "test" just to see if the toolchain
is working correctly. Doesn't actually do anything.
-------------------------------------------------*/
int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}