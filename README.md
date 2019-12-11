# CS 100 Programming Project

> Authors: Dylan McDowell (862075021) and Julien Martin-Prin (X673662)

*Winter Quarter, 2019*

## Introduction

This project is about to create a shell. The shell should be able to understand what the user want to do. The user should be able to use the bash commands available in the **"/bin/bash"** folder. The shell should also be able to interpret multiple commands inputs with differents connectors such as semi-colon (**;**), and (**&&**) and or (**||**). 
These connector have different functions. For example, the command after the and connector should execute only when the previous command succeed and the command after the or connector should execute only if the previous command failed.

To proceed, we will use a parse tree by associating a priority to each connector, depending on their function. For example, the semi-colon connector has a lower priorty than the or connector. So we will use a parsing fucntion that separates each command and then we will build a tree by using the connectors and their priority. Then, after getting the parse tree, we will execute command and then return their value (succed or not, executed or not) so that we can execute the next function depending on this result.

## OMT diagram

<img src="images/OMT Diagram 2.png" with="1000">

## Class Description

**CommandBase**

The CommandBase class will serve as the interface for the composite. It has one pure virtual function, execute(), and no data members. Each class, therefore, is distinguishable by it's implementation of the execute() function.

**Command**

This is the class that represents the command. After parsing, each command will be represented as an instance of this class. It contains the command itself, the arguments and parameters. When execute is called on it, it uses execvp() to perform the command, and return a value dependent on the command's success; -1 for failure, or 0 for a success.

**Exit**

This class will be created by the CommandTree when an exit call is found in the tree. It returns a -1 for it's execute function, otherwise doing nothing.

**ShellTest**

This class implements the test and square bracket([]) commands. By calling the stat function and the correct macros, it determines if a passed in filepath exists. By passing in flags before the filepath, it can distinguish between regular files and directories. It is called by the CommandTree function when it encounters a test call.

**Connector**

This is the class for the connector. This class will recognize each connector and associate it with its corresponding class. The class, and it's subclasses, has a vector of CommandBase pointers(limited to two pointers), and the virtual execute() function. This class serves as a base class for the various types of connectors required. The differents classes for connectors are the following:

* **SemiColon**: The SemiColon class overrides the execute() function by running the leftmost CommandBase's execute(), then the rightmost's. It returns it's leftmost execute() result.
* **Ampersand**: The Ampersand class overrides the execute() function by running the rightmost's execute() only if the leftmost one's succeeds.
* **OrBars**: The OrBars class overrides the execute() function by running the rightmost's execute() only if the leftmost one's fails.
* **Pipe**: The Pipe class overrides the execute() function in order to implement the pipe function in our shell. It executes the leftmost function and outputs it as input for the rightmost function.

Each of these functions' execute() returns a zero if ether it's left or right CommandBase succeeds.

**Exit**

This function is the exit case, it only calls the execute function and exit the program.

**ShellTest**

The Shell Test implements the test command that can be used from the shell. This command checks if the file exists.

**CommandTree**

This class is the base for the parsing tree. After the parsing, we will use this class to create the tree. This class will create each node and leave on our parsing tree. It will recursively run backwards through the tree, seperating the tree by connectors as selected by the parser. As a result, the first commands moving forward will execute first, as they will be at the bottom. The only exception to this is in scenarios using parentheses, where the block of code within the parentheses will be considered as a command until it is processed as one, where the outer parentheses will be removed and the CommandTree will recursively create a subtree from that block

**Parser**

This class will parse the command in order to create a parsing tree. Using the parse member function, CommandParse will output the command prompt, take the input, then pass back a vector of strings, with each word in it's own cell. Also, quotations, parentheses, and semicolons are all automatically given their own cell, and the hash symbol (#) will act as comments.

**ExecuteDecorator**

This class is an interface for the decorator we are using to implement the input and output function for the shell commands. It contains 3 decorators:

* **Input**: This is the decorator for the input. It overrides the execute() function and add an input to the command in the shell.
* **OutputOverride**: This is one of the 2 decorators for the output. This one is called by using '>'. It overrides the execute() function and write the output of the command in a file by overriding the file.
* **OutputAdd**: This the other decorator for the output. This one is called by using '>>'. It overrides the execute() function and write the output in a file but does not override, it just simply add the output to the file.

## Prototyping and Research

After some testing, it is clear how each function is to be used:

* execvp(): This call will be used to execute each parsed command in the Command class. It's worth noting, that when execvp succeeds, it causes the program to exit, requiring the use of child processes.
* fork(): Creates a child process. Returns a value based on whether or not you are in the child process, the parent process, or if something has gone horribly,horribly wrong.
* waitpid(): Similar to the wait() function, this function will prevent a parent process from running until a child process terminates. The waitpid() function differs in that it gives it's caller multiple options as to what child process needs to terminate, how the return is handled, and how that return can be handled.

By using these functions in conjunction, the function caller can create a seperate process to run a command, and still process the result, so that the function that called execvp can pass back specific values(say, if the command failed).

The parsing function was more difficult to implement than originally expected. Taking in input and parsing it by space only was not implemented in the function included in `prototype/`. Rather, the program simply parsed every character into a vector. This will be fixed during the building of Assignment 2.

_Thanks to StackOverflow and [cs.esu.edu](http://www.cs.ecu.edu/karl/4630/sum01/example1.html)(Warning: site is still using http, not https)._

## Roadmap

1. Develop CommandBase base class - Dylan McDowell - [Issue](https://github.com/cs100/assignment-a_01-mcdowell-martin-prin/issues/6)
2. Develop and unit test Command class - Dylan McDowell - [Issue](https://github.com/cs100/assignment-a_01-mcdowell-martin-prin/issues/7)
3. Develop and unit test Connector class and subclasses - Julien Martin-Prin - [Issue](https://github.com/cs100/assignment-a_01-mcdowell-martin-prin/issues/8)
4. Integration test of CommandBase composite pattern - Dylan McDowell - [Issue](https://github.com/cs100/assignment-a_01-mcdowell-martin-prin/issues/9)
5. Re-examine class structure up to this point. Make changes as needed. - Dylan McDowell & Julien Martin-Prin - [Issue](https://github.com/cs100/assignment-a_01-mcdowell-martin-prin/issues/10)
6. Develop and unit test CommandParse class - Julien Martin-Prin - [Issue](https://github.com/cs100/assignment-a_01-mcdowell-martin-prin/issues/11)
7. Develop and unit test CommandTree class - Dylan McDowell - [Issue](https://github.com/cs100/assignment-a_01-mcdowell-martin-prin/issues/12)
8. Integration test CommandParse and CommandTree class - Julien Martin-Prin - [Issue](https://github.com/cs100/assignment-a_01-mcdowell-martin-prin/issues/13)
9. Final re-examination of class structure - Dylan McDowell & Julien Martin-Prin - [Issue](https://github.com/cs100/assignment-a_01-mcdowell-martin-prin/issues/14)
10. Final testing - Julien Martin-Prin & Dylan McDowell - [Issue](https://github.com/cs100/assignment-a_01-mcdowell-martin-prin/issues/15)
11. Release - [Issue](https://github.com/cs100/assignment-a_01-mcdowell-martin-prin/issues/16)
