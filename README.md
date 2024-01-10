GET_NEXT_LINE

DESCRIPTION

Get_Next_Line is a project at 42 School focused on creating a function that reads a file descriptor line by line. This project is essential for understanding file manipulation, dynamic memory allocation, and static variables in C programming.

Features

Reads from a file descriptor line by line.

Handles multiple file descriptors simultaneously (in the bonus part).

Efficiently manages memory to prevent leaks.

Works with variable buffer sizes, defined at compile time.

How to Compile and Run

Compile the project using gcc with the -D flag to set the BUFFER_SIZE (if not, the BUFFER_SIZE will be of size 1:

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o gnl

To run the program, you can use:

./gnl

Core Functions

get_next_line: The main function to read from a file descriptor.

Utility functions like ft_strlen, ft_strjoin, ft_substr, and ft_strchr for string manipulation.

USAGE

Include get_next_line.h in your project to use the function. Ensure to link against the necessary files when compiling your project.

Example

A simple usage example:
```
#include "get_next_line.h"

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
Dependencies

Standard C libraries for I/O operations and memory management.

A Unix-like environment for file descriptor manipulation.

Author

Tulece "anporced"
