#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <vector>

#include "AndToken.hpp"
#include "OrToken.hpp"
#include "Executor.hpp"

using namespace std;

// vector<char*> parseUserInput() {
//     string inputStr;
//     cout << "$ ";
//     getline(cin, inputStr);
//
//     if (inputStr.length() != 0) {
//         istringstream buffer(inputStr);
//         istream_iterator<string> beginning(buffer), end;
//
//         vector<string> inputs(beginning, end);
//         vector<char*> returnInputs;
//         returnInputs.reserve(inputs.size());
//
//         for (int i = 0; i < inputs.size(); i++) {
//             returnInputs.push_back(const_cast<char*>(inputs[i].c_str()));
//         }
//         returnInputs.push_back((char*)NULL);
//
//         return returnInputs;
//     }
//     else {
//
//     }
// }
//
// void execute(vector<char*> vectorInput) {
//   // array for storing commands from user input
//   char** arr = &vectorInput[0];
//   pid_t wait_for_result;
//   int status;
//   // fork child process
//   pid_t child_process = fork();
//
//   //Error messages after fork updates
//   if (child_process < 0) {
//       perror("Fork Failed");
//       exit(1);
//   }
//   if (child_process == 0) {
//     // execute command from array of strings
//     execvp(arr[0], arr);
//   }
//   else {
//       // wait for child process to finish
//       wait_for_result = waitpid(child_process, &status, WUNTRACED);
//   }
// }

int main() {
    while (true) {
        vector<char*> input = parseUserInput();
        execute(input);
    }
}
