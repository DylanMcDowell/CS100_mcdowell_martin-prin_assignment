#ifndef _TEST_TEST_HPP_
#define _TEST_TEST_HPP_

#include "../header/Test.hpp"

TEST(TestTest, NoFlagTest){
	vector<string> v;
	v.push_back("unit_tests/test_test.hpp");
	ShellTest test(v);
	EXPECT_EQ(test.execute(), 0);
}

#endif
