#include "../header/Command.hpp"
#include "../header/CommandBase.hpp"
#include "command_test.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
