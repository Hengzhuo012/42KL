*This project has been created as part of the 42 curriculum by zheng.*

# Libft

## Description
Libft is the first project from 42 core programme. It is part of Milestone 0.

## Instructions
List of commands to run with a description.
* `make` - Compiles all source files into 'libft.a'.
* `make clean` - Removes object files.
* `make fclean` - Removes object files and 'libft.a'.
* `make re` - Performs 'fclean' followed by 'make'.

## Resources
List of references and description of how AI was used.
* [Man Pages] - https://man7.org/linux/man-pages/
* **Usage of AI**
	* **AI used** - Gemini and Google AI Overview
	* **Debugging** - Check for edge cases that got ignored or some infinite loop made. For example, checking if the passed function is NULL.
	* **Explaination** - Understanding functions better for more complex functions such as ft_lstmap for when del function is used.

## Library
Functions created in the library with a detailed description.
* Part 1 - Libc functions
  * `ft_isalpha` - check if the character is an alphabet.
  * `ft_isdigit` - check if the character is a digit.
  * `ft_isalnum` - check if the character is a digit or an alphabet.
  * `ft_isascii` - check if the character is in 7-bit ascii.
  * `ft_isprint` - check if the character is printable.
  * `ft_strlen` - calculate the length of a string.
  * `ft_memset` - fill memory with a constant byte.
  * `ft_bzero` - writing zero to a string.
  * `ft_memcpy` - copy memory area.
  * `ft_memmove` - copy memory area safely.
  * `ft_strlcpy` - copy string to a specific size.
  * `ft_strlcat` - concatenate string to a specific size.
  * `ft_toupper` - convert character to uppercase.
  * `ft_tolower` - convert character to lowercase.
  * `ft_strchr` - locate character in string.
  * `ft_strrchr` - locate character in string from the back.
  * `ft_strncmp` - compare two strings up to n bytes.
  * `ft_memchr` - scan memory for a character.
  * `ft_memcmp` - compare memory areas.
  * `ft_strnstr` - locate a substring in a string.
  * `ft_atoi` - convert a string to an integer.
  * `ft_calloc` - allocate and clear memory.
  * `ft_strdup` - duplicate a string.

* Part 2 - Additional functions
  * `ft_substr` - extract a substring from a string.
  * `ft_strjoin` - concatenate two strings into a new string.
  * `ft_strtrim` - trim the beginning and end of a string with reference characters.
  * `ft_split` - split a string using a delimiter character.
  * `ft_itoa` - convert an integer to a string.
  * `ft_strmapi` - apply a function to each character of a string.
  * `ft_striteri` - apply a function to each character of a string with its index.
  * `ft_putchar_fd` - output a character to a file descriptor.
  * `ft_putstr_fd` - output a string to a file descriptor.
  * `ft_putendl_fd` - output a string followed by a newline to a file descriptor.
  * `ft_putnbr_fd` - output an integer to a file descriptor.

* Part 3 - Linked list
  * `ft_lstnew` - create a new list node.
  * `ft_lstadd_front` - add a node at the beginning of a list.
  * `ft_lstsize` - count the number of nodes in a list.
  * `ft_lstlast` - find the last node of a list.
  * `ft_lstadd_back` - add a node at the end of a list.
  * `ft_lstdelone` - free a single node's content.
  * `ft_lstclear` - free a list and all its nodes.
  * `ft_lstiter` - iterate through a list and apply a function to each node.
  * `ft_lstmap` - iterate through a list, apply a function on each node's content, and create a new list with the new contents.
