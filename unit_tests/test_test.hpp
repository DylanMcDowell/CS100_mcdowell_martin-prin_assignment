#ifndef _TEST_TEST_HPP_
#define _TEST_TEST_HPP_

#include "../header/Test.hpp"

TEST(TestTest, NoFlagTest){
	vector<string> v;
	v.push_back("unit_tests/test_test.hpp");
	ShellTest test(v);
	EXPECT_EQ(test.execute(), 0);
}

TEST(TestTest, eFlagTest){
	vector<string> v;
	v.push_back("-e");
	v.push_back("unit_tests/test_test.hpp");
	ShellTest test(v);
	EXPECT_EQ(test.execute(), 0);
}

TEST(TestTest, eFlagDir){
	vector<string> v;
	v.push_back("-e");
	v.push_back("unit_tests");
	ShellTest test(v);
	EXPECT_EQ(test.execute(), 0);
}

TEST(TestTest, fFlagTest){
        vector<string> v;
        v.push_back("-f");
        v.push_back("unit_tests/test_test.hpp");
        ShellTest test(v);
        EXPECT_EQ(test.execute(), 0);
}

TEST(TestTest, fFlagFail){
        vector<string> v;
        v.push_back("-f");
        v.push_back("unit_tests");
        ShellTest test(v);
        EXPECT_EQ(test.execute(), 1);
}

TEST(TestTest, dFlagTest){
        vector<string> v;
        v.push_back("-d");
        v.push_back("unit_tests");
        ShellTest test(v);
        EXPECT_EQ(test.execute(), 0);
}

TEST(TestTest, dFlagFail){
        vector<string> v;
        v.push_back("-d");
        v.push_back("unit_tests/test_test.hpp");
        ShellTest test(v);
        EXPECT_EQ(test.execute(), 1);
}

#endif

