# Simple Shell Project
## About
The goal of the joint project "Simple Shell" is to investigate and comprehend the operation and application of the shell command language.

### Environment
Our shell was created and tested using the Webterm on Ubuntu 20.04 provided by ALX's intranet. We also used VSCode for debugging etc.

### Repository Contents
Our shell contains the following files:

|  **File**  |   **Description**   |
| ------------ | --------------------- |
| shell.c | Contains the main function |
| main.h | Contains C standard library header files, function declarations, the builtin struct, and environ variable |
| builtins.c | Contains builtin functions |
| helpers.c | Contains helper functions |
| search_path.c | Contains function for finding the PATH environment variable |
| search_functions.c | Contains functions used to search for the command|
| execute.c | Contains function that creates a new program to execute the command|
| utils.c | Contains utility functions |
| parse.c | Contains functions that count and tokenize the command |


### How to Install
Clone the repo below and compile the files into an executable using the GCC compiler.
```
https://github.com/Cyril26/simple_shell
```

### Compilation

The following flags were used to compile the code:
     $ gcc -Wall -Werror -pedantic *.c -o hsh

### Authors

* [**Joel Cyril Odoom**](https://github.com/Cyril26)
* [**Nick Omweri**](https://github.com/NickOmweri)
