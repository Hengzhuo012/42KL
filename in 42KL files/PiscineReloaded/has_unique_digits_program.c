int	has_unique_digits(char *str);

#include <unistd.h>
int	main(int ac, char **av)
{
	char	c;

	(void)ac;
	c = has_unique_digits(av[1]) + '0';
	write(1, &c, 1);
}
