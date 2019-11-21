#include "Parser.hpp"

TEST(parserTest1, parseLine) {
	Parser* test = new Parse();
	string line = "echo \"Hello World!\"";
	vector<string> result = parseLine(line);

	vector<string> expected;
	expected.push_back("echo");
	expected.push_back("\"Hello World!\"");

	EXPECT_EQ(result, expected);
}
