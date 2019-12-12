#ifndef _OUTPUT_ADD_TEST_HPP_
#define _OUTPUT_ADD_TEST_HPP_

TEST(OutputAddTest, EmptyFileOut){
        cout << "Please ensure that no file exists in unit_tests/ called \"outaddtest1.txt\"" << endl;
        vector<string> testVector;
        testVector.push_back("echo");
	testVector.push_back("Hello World!");
        testVector.push_back("\0");
        CommandBase* cmd = new Command(testVector);
        CommandBase* out = new OutputAdd(cmd, "unit_tests/outaddtest1.txt");
	EXPECT_EQ(out->execute(), 0);
        cout << "Examine unit_tests/outtest.txt for results. Should contain one greeting." << endl;
        delete out;
}

TEST(OutputAddTest, FilledFileOut){
	cout << "Please ensure that unit_tests/ has a file called \"outaddtest2.txt\"" << endl;
        vector<string> testVector;
        testVector.push_back("echo");
        testVector.push_back("Hello World! Again!");
        testVector.push_back("\0");
        CommandBase* cmd = new Command(testVector);
        CommandBase* out = new OutputAdd(cmd, "unit_tests/outaddtest2.txt");
        EXPECT_EQ(out->execute(), 0);
        cout << "Examine unit_tests/outtest.txt for results. Should contain two greetings." << endl;
        delete out;
}

#endif
