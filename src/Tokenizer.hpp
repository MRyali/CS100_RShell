#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <unistd.h>
#include <vector>

using namespace std;

class Tokenizer {
    private:
        string inputStr;

    public:
        Tokenizer(string inputStr) {
            this->inputStr = inputStr;
        }

        vector<char*> tokenize() {
            if (inputStr.length() != 0) {
                istringstream buffer(inputStr);
                istream_iterator<string> beginning(buffer), end;

                vector<string> inputs(beginning, end);
                vector<char*> returnInputs;
                returnInputs.reserve(inputs.size());

                for (int i = 0; i < inputs.size(); i++) {
                    returnInputs.push_back(const_cast<char*>(inputs[i].c_str()));
                }
                returnInputs.push_back((char*)NULL);

                return returnInputs;
            }
    }
};
