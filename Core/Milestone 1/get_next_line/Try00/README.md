*This project has been created as part of the 42 curriculum by zheng.*

# get_next_line

## Description
get_next_line is part of a project from 42KL milestone 1. It is used to get a new line from a file.

## Instructions
List of commands to run with a description.
* Use `cc -Wall -Wextra -Werror` followed by `main.c` `get_next_line.c` `get_next_line_utils.c` to compile.
* Use `-D BUUFER_SIZE=n` where n is a number to set a buffer size
`cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c`
* For bonus, replace `get_next_line.c` with `get_next_line_bonus.c` and `get_next_line_utils.c` with `get_next_line_utils_bonus.c`
`cc -Wall -Wextra -Werror main.c get_next_line_bonus.c get_next_line_utils_bonus.c`

## Resources
List of references and description of how AI was used.
* [Man Pages] - https://man7.org/linux/man-pages/
* **Usage of AI**
	* **AI used** - Gemini and Google AI Overview
	* **Debugging** - Check for edge cases that got ignored.
	* **Explaination** - Understanding functions better for more complex functions such as how file descriptor affects the function.

## Explaination
get_next_line get a new line from a file.
### Mandatory Part
* get a new line from a single file.
### Bonus part
* get a new line from multiple files. It uses an array to store each new lines with its own file descriptor.
