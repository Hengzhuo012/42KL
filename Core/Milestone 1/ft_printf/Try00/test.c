#include <stdio.h>

int	main(void)
{
	char	*test;

	test = "%#-0 +20.5c\n%#-0 +20.5s\n%#-0 +20.5p\n%#-0 +20.5d\n\
%#-0 +20.5i\n%#-0 +20.5u\n%#-0 +20.5x\n%#-0 +20.5X\n%%\n";
	printf(test, 'c', "test", (void *)test, 42, 42, 42, 42, 42);
	printf("%-10c", 'c');
	return (0);
}
