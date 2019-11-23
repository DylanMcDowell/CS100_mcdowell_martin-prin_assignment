#ifndef _SEMICOLON_TEST_HPP_
#define _SEMICOLON_TEST_HPP_

#include "../header/CommandBase.hpp"
#include "../header/Connector.hpp"
#include "../header/SemiColon.hpp"
#include "../header/Command.hpp"
#include "gtest/gtest.h"
#include <iostream>

TEST(SemiColonTest, EchoEcho){
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
        CommandBase* semi = new SemiColon(cmd1, cmd2);
        EXPECT_EQ(amp->execute(), 0);
}

TEST(AmpersandTest, FailEcho){
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
        CommandBase* amp = new Ampersand(cmd1, cmd2);
        EXPECT_EQ(amp->execute(), 1);
}

