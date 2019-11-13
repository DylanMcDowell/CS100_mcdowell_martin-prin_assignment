#ifndef _COMMAND_TEST_HPP_
#define _COMMAND_TEST_HPP_

#include "../header/Command.hpp"
#include "gtest/gtest.h"


TEST(CommandTest, EchoExecute) {
	vector<string> testVector;
	testVector.push_back("echo");
	testVector.push_back("Hello");
	testVector.push_back("World");
	testVector.push_back("\0");
	CommandBase* testC = new Command(testVector);
	EXPECT_EQ(testC->execute(), 1);
}


#endif
