#ifndef _PIPE_TEST_HPP_
#define _PIPE_TEST_HPP_

TEST(PipeTest, EchoEcho){
	vector<string> testVector;
        testVector.push_back("echo");
        testVector.push_back("Hello World");
        testVector.push_back("\0");
	vector<string> testVector2;
	testVector2.push_back("echo");
	testVector2.push_back("\0");
        CommandBase* testC1 = new Command(testVector);
	CommandBase* testC2 = new Command(testVector2);
	CommandBase* testPipe = new Pipe(testC1, testC2);
        EXPECT_EQ(testPipe->execute(), 0);
        delete testPipe;
}

TEST(PipeTest, lsEcho){
	vector<string> testVector;
        testVector.push_back("ls");
        testVector.push_back("\0");
        vector<string> testVector2;
        testVector2.push_back("echo");
        testVector2.push_back("\0");
        CommandBase* testC1 = new Command(testVector);
        CommandBase* testC2 = new Command(testVector2);
        CommandBase* testPipe = new Pipe(testC1, testC2);
        EXPECT_EQ(testPipe->execute(), 0);
        delete testPipe;
}

#endif

