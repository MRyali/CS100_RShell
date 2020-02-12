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

    istringstream buffer(inputStr);
    istream_iterator<string> beginning(buffer), end;

    vector<string> inputs(beginning, end);
    return inputs.data();
}

int main() {
    
}
