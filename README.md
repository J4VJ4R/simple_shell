# NAME
This is a simple_shell

# SYNOPSIS
simple_shell is a command line interpretation that takes an input that can be interactive or non-interactive, parses, and then based on parsing returns an execution of the command entered as output.

# DESCRIPTION
simple_shell starts its process initially when the ./shell command is run in the terminal, at that moment, the shell starts working and gives us as initial input the $ cisfun prompt, where the command line to be written must be written. taken as the input and executed when enter is pressed. The result of the command that is entered will be printed in the terminal with the prompt waiting for the following command line.

# Non-interactive mode:
Is a command line interpreter E.x:
$ gcc -Wall -Werror -Wextra -pedantic *.c -o ./shell
$ echo "/bin/ls" | ./shell
AUTHORS _execute.c counthand.c shell.h mini_shell.c man_1_simple_shell README.md 
$
# Interactive mode:
Is a command line interpreter Ex:
$ gcc -Wall -Werror -Wextra -pedantic .c -o ./shell
$ ./shell
#cisfun$ ls
AUTHORS _execute.c counthand.c shell.h mini_shell.c man_1_simple_shell README.md 
#cisfun$
