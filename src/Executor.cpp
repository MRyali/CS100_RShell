#include "Executor.hpp"

using namespace std;

Executor::Executor() {}

int Executor::execute(vector<char*> vectorInput) {
  // array for storing commands from user input
  char** arr = &vectorInput[0];
  pid_t wait_for_result;
  int status;
  // fork child process
  pid_t child_process = fork();

  //Error messages after fork updates
  if (child_process < 0) {
      perror("Fork Failed");
      exit(1);
  }
  if (child_process == 0) {
    // execute command from array of strings
    execvp(arr[0], arr);
  }
  else {
      // wait for child process to finish
      wait_for_result = waitpid(child_process, &status, WUNTRACED);
  }
  return 0;
}
