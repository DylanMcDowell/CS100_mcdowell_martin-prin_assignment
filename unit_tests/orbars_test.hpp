#ifndef _ORBARS_TEST_HPP_
#define _ORBARS_TEST_HPP_

#include "../header/CommandBase.hpp"
#include "../header/Connector.hpp"
#include "../header/OrBars.hpp"
#include "../header/Command.hpp"
#include "gtest/gtest.h"
#include <iostream>

TEST(OrBarsTest, EchoEcho){
        vector<string> testVector1;
        testVector1.push_back("echo");
        testVector1.push_back("Hello");
        testVector1.push_back("\0");
        CommandBase* cmd1 = new Command(testVector1);

        vector<string> testVector2;
        testVector2.push_back("echo");
        testVector2.push_back("World");
        testVector2.push_back("\0");
        CommandBase* cmd2 = new Command(testVector2);
        CommandBase* orbars = new OrBars(cmd1, cmd2);
        EXPECT_EQ(orbars->execute(), 0);
}

TEST(OrBarsTest, FailEcho){
        vector<string> testVector1;
        testVector1.push_back("eho");
        testVector1.push_back("Hello");
        testVector1.push_back("\0");
        CommandBase* cmd1 = new Command(testVector1);

        vector<string> testVector2;
        testVector2.push_back("echo");
        testVector2.push_back("World");
        testVector2.push_back("\0");
        CommandBase* cmd2 = new Command(testVector2);
        CommandBase* orbars = new OrBars(cmd1, cmd2);
        EXPECT_EQ(orbars->execute(), 0);
}

TEST(OrBarsTest, EchoFail){
        vector<string> testVector1;
        testVector1.push_back("echo");
        testVector1.push_back("Hello");
        testVector1.push_back("\0");
        CommandBase* cmd1 = new Command(testVector1);

        vector<string> testVector2;
        testVector2.push_back("eo");
        testVector2.push_back("World");
        testVector2.push_back("\0");
        CommandBase* cmd2 = new Command(testVector2);
        CommandBase* orbars = new OrBars(cmd1, cmd2);
        EXPECT_EQ(orbars->execute(), 0);
}

TEST(OrBarsTest, FailFail){
        vector<string> testVector1;
        testVector1.push_back("eco");
        testVector1.push_back("Hello");
        testVector1.push_back("\0");
        CommandBase* cmd1 = new Command(testVector1);

        vector<string> testVector2;
        testVector2.push_back("eho");
        testVector2.push_back("World");
        testVector2.push_back("\0");
        CommandBase* cmd2 = new Command(testVector2);
        CommandBase* orbars = new OrBars(cmd1, cmd2);
        EXPECT_EQ(orbars->execute(), 1);
}


#endif
