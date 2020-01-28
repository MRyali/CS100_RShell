#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string cmd = "";
	cout << "Enter a command:" << endl;
	cin >> cmd ;
	string currCmd = "";

	vector<string> commands;

	for (int i = 0; i < cmd.length(); i++) {
		int k = i;
		while ((cmd.at(i) != '|') || (cmd.at(i) != '&') || (cmd.at(i) != ';')) {
			currCmd += cmd.at(i);
			i++;
		}
		++i;
		commands.push_back(currCmd);
		currCmd = "";
	}

	for (int j = 0; j < commands.size(); j++) {
		cout << commands.at(j) << " ";
	}
}
