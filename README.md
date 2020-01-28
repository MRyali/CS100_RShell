# CS 100 Programming Project

# Project Information
* Winter 2020
* Collaborators
  * Kashyap Panda (862076026)
  * Mayur Ryali (862076991)
  
<h1>Introduction</h1>

<d1>
    <dd>This is the rshell in C++ project by Mayur Ryali and Kashyap Panda where we will be creating a CLI shell. A shell is a user interface that allows for access to an operating system’s services. The program will be able to eventually prompt the user with a ‘$’, read in lines of commands that support logical connectors from standard input, and execute the commands using “fork”, “execvp”, and “waitpid”. The program will repeat the above steps until an exit command is executed. Any number of commands and combinations of said commands should be able to be chained together using the connectors. To represent the commands and operators in our program, we will be using the composite design pattern. The token class is the component, the executor class is a leaf, and the tokenizer class is the composite. </dd>    
</d1>

<br>

<h1>Classes</h1>

*Token Class*
<d1>
<dd>This is an abstract parent class for different types of token or a single element of a programming language. This can include  keywords, 
identifiers, operators,separators, literals, or even punctuation. Some of the defined functions will be connector functions (AND, OR, etc.) 
and functions to store the commands and arguments. 
This class will have a subclass that will implement vectors that contain the left and right commands in a chained together command input. 
This will allow for easier access and execution of the chained commands. 
Another subclass is the command token class which will take implement a vector that will store the arguments a given command can take. </dd>
</d1>

<br>

*Executor Class*
<d1>
<dd> leaf class whose purpose is the execute command inputs. It will take in a vector of tokens into its constructor. This class will include 
and “execute” function that will return a boolean based on the presence of errors upon execution. </dd>
</d1>

<br>

*Tokenizer Class*
<d1>
<dd>Takes in user input as a vector of characters and run it through a tokenizer function that will return a vector of tokens corresponding to 
each of the commands the user has typed in.</dd>
</d1>

 
