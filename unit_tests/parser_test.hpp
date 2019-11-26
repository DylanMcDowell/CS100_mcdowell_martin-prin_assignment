#include "gtest/gtest.h"
#include "../header/Parser.hpp"

TEST(parserTest, parseLine) {
	Parser* test = new Parser();
	string line = "echo \"Hello World!\"";
	vector<string> result = test->parseLine(line);

	vector<string> expected;
	expected.push_back("echo");
	expected.push_back("Hello World!");

	EXPECT_EQ(result, expected);
}

TEST(parenthesis, parseLine) {
	Parser* test = new Parser();
	string line = "(parenthesis test))";
	vector<string> result = test->parseLine(line);

	vector<string> expected;
	expected.push_back("(");
	expected.push_back("parenthesis");
	expected.push_back("test");
	expected.push_back(")");
	expected.push_back(")");
	
	EXPECT_EQ(result, expected);
}

TEST(mixed, parseLine) {
	Parser* test = new Parser();
	string line = "ls -a; echo hello && mkdir test || echo \"world\"; git status || (exit)";
	vector<string> result test->parseLine(line);

	vector<string> expected;
	expected.push_back("ls");
	expected.push_back("-a");
	expected.push_back(";");
	expected.push_back("echo");
	expected.push_back("hello");
	expected.push_back("&&");
	expected.push_back("mkdir");
	expected.push_back("test");
	expected.push_back("||");
	expected.push_back("echo");
	expected.push_back("world");
	expected.push_back(";");
	expected.push_back("git");
	expected.push_back("status");
	expected.push_back("||");
	expected.push_back("(");
	expected.push_back("exit");
	expected.push_back(")");

	EXPECT_EQ(result, expected);
}
