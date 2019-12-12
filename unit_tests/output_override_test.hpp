#ifndef _OUTPUT_OVERRIDE_TEST_HPP_
#define _OUTPUT_OVERRIDE_TEST_HPP_

TEST(OuputOverrideTest, EmptyFileOut){
        cout << "Please ensure that no file exists in unit_tests/ called \"outtest2.txt\"" << endl;
        vector<string> testVector;
        testVector.push_back("echo");
        testVector.push_back("Hello World!");
        testVector.push_back("\0");
        CommandBase* cmd = new Command(testVector);
        CommandBase* out = new OutputAdd(cmd, "unit_tests/outtest2.txt");
        EXPECT_EQ(out->execute(), 0);
        cout << "Examine unit_tests/outtest.txt for results. Should contain one greeting." << endl;
        delete out;
}

TEST(OutputOverrideTest, FilledFileOut){
        vector<string> testVector;
        testVector.push_back("echo");
        testVector.push_back("Hello World! Again!");
        testVector.push_back("\0");
        CommandBase* cmd = new Command(testVector);
        CommandBase* out = new OutputAdd(cmd, "unit_tests/outtest2.txt");
        EXPECT_EQ(out->execute(), 0);
        cout << "Examine unit_tests/outtest.txt for results. Should contain two greetings." << endl;
        delete out;
}

#endif

