#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <unistd.h>

using namespace std;

string* parseUserInput() {
    string inputStr;
    cout << "$ ";
    getline(cin, inputStr);

    if (inputStr.length() != 0) {
        istringstream buffer(inputStr);
        istream_iterator<string> beginning(buffer), end;

        vector<string> inputs(beginning, end);
        return inputs.data();
    }
    else {
        return nullptr;
    }
}

int main() {
    while (true) {
        string* input[] = parseUserInput();
        execute(input);
    }
}
