#ifndef _COMMANDTREE_TEST_HPP_
#define _COMMANDTREE_TEST_HPP_

#include "../header/CommandTree.hpp"
#include "gtest/gtest.h"

TEST(CommandTreeTest, InputTest){
	CommandTree cmdT;
	cmdT.buildTree();
	std::cout << "buildTree finished" << std::endl;
	cmdT.execute();
}

#endif
