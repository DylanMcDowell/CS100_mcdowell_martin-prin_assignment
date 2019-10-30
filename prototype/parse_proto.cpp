#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<string> inputs;
	int i;

	string input;
	getline(cin, input);
	string parseholder = "";

	for(i = 0; i < input.length(); i++){
		cout << "\"" << input.at(i) << "\"" << flush;
		if(input.at(i) == ' '){
			inputs.push_back(parseholder);
			parseholder = "";
		}
		else{
			parseholder = parseholder + input.at(i);
		}
	}
	inputs.push_back(parseholder);

	for(i = 0; i < inputs.size(); i++){
		cout << input.at(i) << endl;
	}
}
