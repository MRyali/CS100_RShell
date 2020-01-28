#include <iostream>
#include <unistd.h>

void forkAndWaitTest() {
  pid_t childProcess = fork();

  pid_t wait_result;
  int stat_loc;

  if (childProcess == 0) {
    std::cout << "This is a child process." << std::endl;
    std::cout << "PID ID: " << getpid() << ", Child PID: " << childProcess << '\n';

    std::cout << "Waiting for 1 second..." << '\n';
    sleep(1);
  } else {
    wait_result = waitpid(childProcess, &stat_loc, WUNTRACED);
    std::cout << stat_loc << '\n';
    std::cout << "This is the parent process." << std::endl;
    std::cout << "PID ID: " << getpid() << ", Child PID: " << childProcess << '\n';
  }
}

int main() {
  char *argv[] = {"ls", "-l", NULL};
  execvp(argv[0], argv);
  return 0;
}
