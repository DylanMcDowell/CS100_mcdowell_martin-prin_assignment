#include "../header/Command.hpp"
#include "../header/CommandBase.hpp"
#include "command_test.hpp"
#include "ampersand_test.hpp"
#include "semicolon_test.hpp"
#include "exit_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
