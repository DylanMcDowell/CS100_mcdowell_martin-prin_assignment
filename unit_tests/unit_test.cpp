#include "../header/Command.hpp"
#include "../header/CommandBase.hpp"
#include "command_test.hpp"
#include "ampersand_test.hpp"
#include "semicolon_test.hpp"
#include "orbars_test.hpp"
#include "exit_test.hpp"
#include "parser_test.hpp"
#include "commandtree_test.hpp"
#include "test_test.hpp"
#include "input_test.hpp"
#include "output_add_test.hpp"
#include "output_override_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
