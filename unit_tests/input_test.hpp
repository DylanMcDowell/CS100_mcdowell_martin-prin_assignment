#ifndef _INPUT_TEST_HPP_
#define _INPUT_TEST_HPP_

#include "../header/CommandTree.hpp"
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

TEST(InputTest, EchoInput){
	cout << "Ensure unit_tests/inTest1.txt has \"Hello World\" written in it." << endl;
	vector<string> testVector;
        testVector.push_back("echo");
        testVector.push_back("\0");
	CommandBase* cmd = new Command(testVector);
	CommandBase* in = new Input(cmd, "unit_tests/inTest1.txt");
	cout << "Expected output is \"Hello World\". Actual output: " << endl;
	EXPECT_EQ(in->execute(), 0);
	delete in;
}

TEST(InputTest, FailInput){
        cout << "Ensure unit_tests/fail.txt does not exist." << endl;
        vector<string> testVector;
        testVector.push_back("echo");
        testVector.push_back("\0");
        CommandBase* cmd = new Command(testVector);
        CommandBase* in = new Input(cmd, "unit_tests/fail.txt");
        EXPECT_EQ(in->execute(), 1);
        delete in;
}


#endif
