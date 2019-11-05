#ifndef _COMMAND_BASE_HPP_
#define _COMMAND_BASE_HPP_

//Interface class CommandBase for CommandBase composite pattern

class CommandBase{
   public:
	/*Goes through the tree and executes
	 *each command in order with accordance
	 *to connector rules.
	 */

	virtual int execute() = 0;
}

#endif
