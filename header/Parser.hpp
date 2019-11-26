#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Parser
{
	private:
		vector<string> cmdParse;
		string parse; //temporary variable
		char c; //the charcater for the input stream

		unsigned int str2int(const char c1)
		{
			int result = 0;
			
			if (c1 == ';')
			{
				result = 1;
			}
			else if (c1 == 0x20)
			{
				result = 2;
			}
			else if (c1 == '\"')
			{
				result = 3;
			}

			return result;
		};

	public:
		/* Constructors*/
		Parser() {};

		vector<string> parseLine(string line) 
		{
			string temp;

			for (int i = 0; i < line.length(); i++)
			{
				c = line[i];

				switch (str2int(c))
				{
					case 1: // case ";"
						cmdParse.push_back(parse);
						cmdParse.push_back(";");
						parse = "";
						break;

					case 2: // case " "
						cmdParse.push_back(parse);
						parse = "";
						break;

					case 3: // case "\""
						int j;

						temp = "";

						for (j = i + 1; j < line.length(); j++)
						{
							temp = line[j];
							
							if (temp != "\"")
							{
								parse += temp;
							}
							else
							{
								cmdParse.push_back(parse);
								parse = "";
								break;
							}

						}
						
						i = j;
						parse = "";
						break;

					default:
						parse += c;
						break;
				}
			}

			return cmdParse;
		};
		
};

#endif
