#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <readline/readline.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

using namespace std;

void execute(string *arr[]) {
  // array for storing commands from user input
  pid_t wait_for_result;
  int status;
  // fork child process
  pid_t child_process = fork();

  if (child_process == 0) {
    // execute command from array of strings
    execvp(arr[0], arr);
    // wait for 1 second after executing command
    sleep(1);
  }
  else {
      // wait for child process to finish
      wait_for_result = (child_process, &status, WUNTRACED);
      cout << "Fork() failed" << endl;
      return;
  }
  // wait 10 seconds
  sleep(10);
  // kill child process
  kill(child_process, SIGKILL);
}

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