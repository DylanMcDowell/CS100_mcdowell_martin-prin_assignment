#ifndef _COMMANDTREE_TEST_HPP_
#define _COMMANDTREE_TEST_HPP_

#include "../header/CommandTree.hpp"
#include "gtest/gtest.h"

//TEST(CommandTreeTest, InputTest){
//	CommandTree cmdT;
//	cmdT.buildTree();
//	std::cout << "buildTree finished" << std::endl;
//}

TEST(CommandTreeTest, SingleEcho){
	vector<string> v;
	v.push_back("echo");
	v.push_back("Hello World");
	CommandTree cmdT;
	cmdT.vectorBuild(v);
	cmdT.execute();
}

TEST(CommandTreeTest, SingleConnector){
	vector<string> v;
        v.push_back("echo");
        v.push_back("Hello");
	v.push_back(";");
	v.push_back("echo");
	v.push_back("World");
        CommandTree cmdT;
        cmdT.vectorBuild(v);
        cmdT.execute();
}

TEST(CommandTreeTest, MultiConnector){
	vector<string> v;
        v.push_back("echo");
        v.push_back("Hello World");
	v.push_back("||");
	v.push_back("echo");
	v.push_back("Critical Failure!");
	v.push_back("&&");
	v.push_back("echo");
	v.push_back("Critical Success!");
        CommandTree cmdT;
        cmdT.vectorBuild(v);
        cmdT.execute();
}

TEST(CommandTreeTest, ExitTest){
	vector<string> v;
        v.push_back("exit");
        v.push_back(";");
	v.push_back("echo");
	v.push_back("This should not print");
	v.push_back(";");
	v.push_back("echo");
	v.push_back("failure");
        CommandTree cmdT;
        cmdT.vectorBuild(v);
        cmdT.execute();
}

TEST(CommandTreeTest, ParenthesesTest){

}

#endif
