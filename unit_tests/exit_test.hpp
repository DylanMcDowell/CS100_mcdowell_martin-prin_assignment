#ifndef _EXIT_TEST_HPP_
#define _EXIT_TEST_HPP_

#include "../header/CommandBase.hpp"
#include "../header/exit.hpp"

TEST(ExitTest, PlainExit){
	CommandBase* testE = new Exit();
	EXPECT_EQ(testE->execute(), 1);
	delete testE;
}

#endif
