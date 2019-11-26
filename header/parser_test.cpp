#include "gtest/gtest.h"
#include "Parser.hpp"

TEST(parserTest1, parseLine) {
	Parser* test = new Parser();
	string line = "echo \"Hello World!\"";
	vector<string> result = test->parseLine(line);

	vector<string> expected;
	expected.push_back("echo");
	expected.push_back("\"Hello World!\"");

	EXPECT_EQ(result, expected);
}
