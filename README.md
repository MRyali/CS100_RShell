# CS 100 Programming Project

# Project Information
* Winter 2020
* Collaborators
  * Kashyap Panda (862076026)
  * Mayur Ryali (862076991)
  
* Introduction

    This is the rshell in C++ project by Mayur Ryali and Kashyap Panda where we will be creating a CLI shell. A shell is a user interface that allows for access to an operating system’s services. The program will be able to eventually prompt the user with a ‘$’, read in lines of commands that support logical connectors from standard input, and execute the commands using “fork”, “execvp”, and “waitpid”. The program will repeat the above steps until an exit command is executed. Any number of commands and combinations of said commands should be able to be chained together using the connectors. To represent the commands and operators in our program, we will be using the composite design pattern. The token class is the component, the executor class is a leaf, and the tokenizer class is the composite. 
