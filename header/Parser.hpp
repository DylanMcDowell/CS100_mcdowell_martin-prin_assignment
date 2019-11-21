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
		string c; //the charcater for the input stream

		constexpr unsigned int str2int(const string str)
		{
			int result = 0;
			
			if (str == ";")
			{
				result = 1;
			}
			else if (str == " ")
			{
				result = 2;
			}
			else if (str == "\"");
			{
				result = 3;
			}

			return result;
		};

	public:
		/* Constructors*/
		Parser() { this->parse = ""; this->c = ""; };

		vector<string> parse(string line) 
		{
			for (int i = 0; i < line.length(); i++)
			{
				c = line[i];

				switch (str2int(c))
				{
					case 1:
						cmdParse.push_back(parse);
						cmdParse.push_back(";");
						parse = "";
						break;

					case 2:
						cmdParse.push_back(parse);
						parse = "";
						break;

					case 3:
						cmdParse.push_back(parse);
						parse = "";
						int j;

						string temp = "";

						for (j = i; j < line.length(); j++)
						{
							temp = line[j];
							
							if (temp != "\"")
							{
								parse += temp;
							}
							else
							{
								cmdParse.push_back("\"" + parse + "\"");
								parse = "";
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
		};
		
};

#endif
