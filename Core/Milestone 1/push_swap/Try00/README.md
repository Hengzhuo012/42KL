*This project has been created as part of the 42 curriculum by zheng, namak.*

# Push_Swap

## Description
push_swap is a part of project from 42KL Milestone 1. It is used to sort a stack in ascending order.

## Instructions
List of commands to run with a description.
* `make` - Compiles all source files into `push_swap.a`.
* `make libft.a` - Compiles all source files into `push_swap.a`.
* `make clean` - Removes object files.
* `make fclean` - Removes object files and `push_swap.a`.
* `make re` - Performs `fclean` followed by `make`.
* `make bonus` - Compiles all bonus source files into `push_swap.a`.

## Resources
List of references and description of how AI was used.
* [Man Pages] - https://man7.org/linux/man-pages/
* Introduction to Algorithms - https://www.cs.mcgill.ca/~akroit/math/compsci/Cormen%20Introduction%20to%20Algorithms.pdf
* Bucket Sort - https://www.geeksforgeeks.org/dsa/bucket-sort-2/
* Merge Sort - https://www.geeksforgeeks.org/dsa/merge-sort/
* **Usage of AI**
	* **AI used** - Gemini and Google AI Overview
	* **Debugging** - Check for edge cases that got ignored.
	* **Explaination** - Understanding the question requirements better in subject.pdf

## Explaination

### Mandatory Part
Sort **`stack a`** containing a random amoung of numbers in ascending order, with an empty **`stack b`**.
* Operations
	* `sa` (swap a) - Swap the first two elements at the top of stack a. Do nothing if there is only one or no elements.
	* `sb` (swap b) - Swap the first two elements at the top of  stack b.
	Do nothing if there is only one or no elements.
	* `ss` - `sa` and `sb` at the same time.

	* `pa` (push a) - Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
	* `pb` (push b) - Tale the first element at the top of a and put it at the top of b. Do nothing if a is empty.

	* `ra` (rotate a) - Shift up all elements of stack a by one. The first element becomes the last one.
	* `rb` (rotate b) - Shift up all elemetns of stack b by one. The first element becomes the first one.
	* `rr` - `ra` and `rb` at the same time.

	* `rra` (reverse rotate a) - Shift down all elements of stack a by one. The last element becomes the first one.
	* `rrb` (reverse rotate b) - Shift down all elements of stack b by one. The last element becomes the first one.
	* `rrr` - `rra` and `rrb` at the same time.

* Strategies
	* **Simple algorithm** (O(n²))
		* Bubble sort adaption
	* **Medium algorithm** (O(n√n))
		* Bucket sort adaptions with √n buckets.
			Group the values 
	* **Complex algorithm** (O(n log(n)))
		* 

* Flags
	* `--simple` - Forces the use of O(n²) algorithm.
	* `--medium` - Forces the use of O(n√n) algorithm.
	* `--complex` - Forces the use of O(n log(n)) algorithm.
	* `--adaptive` - Forces the use of adaptive algorithm based on disorder. This is the default behavior if no selector is given.
		Disorder - number between 0 and 1 that tells how far the initial `stack a` is from being sorted.
		If the numbers are already in the right order, the disorder is 0. If they are in the worst possible order, the disorder is 1.
		To calculate it, each time a bigger number appears before a smaller one, the closer the disorder is to 1.
		* **Low disorder** - if disorder < 0.2, use O(n²) algorithm.
		* **Medium disorder** - if 0.2 <= disorder < 0.5, use O(n√n) algorithm.
		* **High disorder** - if disorder >= 0.5, use O(n log(n)) algorithm.
	* `--bench` - benchmark mode
		After sorting, display
		* The computed disorder (% with two decimals).
		* The name of the strategy used and its theoretical complexity class.
		* The total number of operations.
		* The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).
		Output is sent to stderr and only appear when the flag is present.

### Bonus Part
Recreate the "checker" program, provided in the project list.