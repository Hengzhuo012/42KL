*This project has been created as part of the 42 curriculum by zheng.*

# ft_printf

## Description
ft_printf is part of a project from 42KL milestone 1. It is used to recreate the printf function in the stdio.h library.

## Instructions
List of commands to run with a description.
* `make` - Compiles all source files into `libftprintf.a`.
* `make libft.a` - Compiles all source files into `libftprintf.a`.
* `make clean` - Removes object files.
* `make fclean` - Removes object files and `libftprintf.a`.
* `make re` - Performs `fclean` followed by `make`.
* `make bonus` - Compiles all bonus source files into `libftprintf.a`.

## Resources
List of references and description of how AI was used.
* [Man Pages] - https://man7.org/linux/man-pages/
* **Usage of AI**
	* **AI used** - Gemini and Google AI Overview
	* **Debugging** - Check for edge cases that got ignored.
	* **Explaination** - Understanding functions better for more complex functions such as if there is precision, 0 flag is ignored.

## Explaination
Printf prints the characters, and prints the conversions differently. It returns the amount of characters outputted.
### Mandatory Part
* check for the conversion type `cspdiuxX%` and called the respective functions to handle it.
	* **`c`** - prints a single character and return 1
	* **`s`** - prints a string and return the length of string
	* **`p`** - prints the pointer in hexadecimal format and return the length of the hexadecimal format
	* **`d`** - prints an integer in base 10 and return the digits of the number and + 1 if the number is negative
	* **`i`** - same as **`d`**
	* **`u`** - prints an unsigned decimal number and return the digits of the number
	* **`x`** - prints a number in hexadecimal lowercase format and return the length of the hexadecimal format
	* **`X`** - same as **`x`** but with uppercase
	* **`%`** - prints `%` and return 1
### Bonus part
* handles flags and precision - `-`, `0`, `.`, `#`, ` `, `+`
	* `(width)` - min chars to output, right-align and padded with spaces
	* `-(width)` - min chars to output, left-align and padded with spaces
	* `0(width)` - min chars to output, right-align and padded with '0'
	* `.(precision)`
		* `string` - max chars output from the string
		* `numbers` - min digits output, padded with '0' if needed, overwrites `0` flag, padded with spaces instead.
	* `#` - applied on `x` and `X`, add prefix `0x` and `0X` respectively
	* ` ` - applied on `d` and `i`, add prefix ` ` if number not negative
	* `+` - same as ` ` but with prefix `+`, overwrites ` ` flag if both exsists