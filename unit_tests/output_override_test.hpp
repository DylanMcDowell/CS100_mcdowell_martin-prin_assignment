#ifndef _OUTPUT_OVERRIDE_TEST_HPP_
#define _OUTPUT_OVERRIDE_TEST_HPP_

TEST(OutputOverrideTest, EmptyFileOut){
        cout << "Please ensure that no file exists in unit_tests/ called \"outovertest1.txt\"" << endl;
        vector<string> testVector;
        testVector.push_back("echo");
        testVector.push_back("Hello World!");
        testVector.push_back("\0");
        CommandBase* cmd = new Command(testVector);
        CommandBase* out = new OutputOverride(cmd, "unit_tests/outovertest1.txt");
        EXPECT_EQ(out->execute(), 0);
        cout << "Examine unit_tests/outtest.txt for results. Should contain one greeting." << endl;
        delete out;
}

TEST(OutputOverrideTest, FilledFileOut){
	cout << "Please ensure that unit_tests/outovertest2.txt exists" << endl;
        vector<string> testVector;
        testVector.push_back("echo");
        testVector.push_back("Hello World! Again!");
        testVector.push_back("\0");
        CommandBase* cmd = new Command(testVector);
        CommandBase* out = new OutputOverride(cmd, "unit_tests/outovertest2.txt");
        EXPECT_EQ(out->execute(), 0);
        cout << "Examine unit_tests/outtest.txt for results. Should contain one greetings." << endl;
        delete out;
}

#endif

