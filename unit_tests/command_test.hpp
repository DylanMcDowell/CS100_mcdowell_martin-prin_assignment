#ifndef _COMMAND_TEST_HPP_
#define _COMMAND_TEST_HPP_

#include "../header/CommandBase.hpp"
#include "../header/Command.hpp"
#include "gtest/gtest.h"
#include <iostream>

TEST(CommandTest, EchoExecute) {
	vector<string> testVector;
	testVector.push_back("echo");
	testVector.push_back("Hello");
	testVector.push_back("\0");
	CommandBase* testC = new Command(testVector);
	EXPECT_EQ(testC->execute(), 0);
	delete testC;
}

TEST(CommandTest, EchoMultiExecute) {
        vector<string> testVector;
        testVector.push_back("echo");
        testVector.push_back("Hello ");
	testVector.push_back("World");
        testVector.push_back("\0");
        CommandBase* testC = new Command(testVector);
        EXPECT_EQ(testC->execute(), 0);
	delete testC;
}

TEST(CommandTest, EchoOpExecute) {
        vector<string> testVector;
        testVector.push_back("echo");
        testVector.push_back("Hello   ");
	testVector.push_back("\bWorld");
        testVector.push_back("\0");
        CommandBase* testC = new Command(testVector);
        EXPECT_EQ(testC->execute(), 0);
	delete testC;
}

TEST(CommandTest, lsExecute) {
        vector<string> testVector;
        testVector.push_back("ls");
        testVector.push_back("\0");
        CommandBase* testC = new Command(testVector);
        EXPECT_EQ(testC->execute(), 0);
	delete testC;
}

TEST(CommandTest, BadExecute) {
        vector<string> testVector;
        testVector.push_back("ech");
        testVector.push_back("Hello");
        testVector.push_back("\0");
        CommandBase* testC = new Command(testVector);
        EXPECT_EQ(testC->execute(), -1);
	delete testC;
}

#endif
