#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <iostream>
#include <string>

using namespace std;

class Parser
{
	private:
		vector<string> cmdParse;
		string parse; //temporary variable
		string c; //the charcater for the input stream

	public:
		/* Constructors*/
		Parse() { parse = ""; c = ""; };

		vector<string> parseLine(string line) 
		{
			for (int i = 0; i < line.length(); i++)
			{
				c = line[i];

				switch (c)
				{
					case ";":
						cmdParse.push_back(parse);
						cmdParse.push_back(";");
						parse = "";
						break;

					case " ":
						cmdParse.push_back(parse);
						parse = "";
						break;

					case "\"":
						cmdParse.push_back(parse);
						parse = "";
						int j;

						string temp = '';

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
