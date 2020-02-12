#include "Tokenizer.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <iterator>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <vector>

using namespace std;

void execute(vector<char*> vectorInput) {
  // array for storing commands from user input
  char** arr = &vectorInput[0];
  pid_t wait_for_result;
  int status;
  // fork child process
  pid_t child_process = fork();

  //Error messages after fork updates
  if (child_process < 0) {
      cout << "Fork Failed" << endl;
      exit(1);
  }
  if (child_process == 0) {
    // execute command from array of strings
    execvp(arr[0], arr);
    sleep(1);
  }
  else {
      // wait for child process to finish
      wait_for_result = waitpid(child_process, &status, WUNTRACED);
  }
}

int main(int argc, char* argv[]) {
    while (true) {
        string inputStr;
        cout << "$ ";
        getline(cin, inputStr);

        Tokenizer t(inputStr);

        vector<char*> input = t.tokenize();
        execute(input);
    }
}
