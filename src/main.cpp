#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

using namespace std;

void execute(vector<char*> vectorInput) {
  // array for storing commands from user input
  char** arr = &vectorInput[0];
  pid_t wait_for_result;
  int status;
  // fork child process
  pid_t child_process = fork();

  if (child_process == 0) {
    // execute command from array of strings
    execvp(arr[0], arr);
  }
  else {
      // wait for child process to finish
      wait_for_result = (child_process, &status, WUNTRACED);
      cout << "Fork() failed" << endl;
  }
}

int main() {
}
