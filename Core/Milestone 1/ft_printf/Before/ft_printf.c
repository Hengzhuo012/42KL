/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:22:46 by zheng             #+#    #+#             */
/*   Updated: 2026/07/31 17:43:38 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//count how many %... (eg %d %s %c), excluding %%
//create arr to store all arguments
//arguments type determine by what the %d or %s is.
//then pass to putchar or putstr etc.

int	count_arguments(const char *s)
{
	char	*flags;
	char	*conversions;
	int		i;

	i = 0;
	flags = "-0.# +";
	conversions = "cspdiuxX";
	while (s[i])
	{
		if (s[i] == '%')
		{
			

//return how much characters outputed
int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		len;

	va_start(args, s);
	i = 0;
	count = 0;
	while(s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
			{
				ft_putchar('%');
				i++;
			}
			else
			{
				len = print(set_mode(s[i + 1], &i), 
			
		}
		else
		{
			ft_putchar(s[i++]);
			count++;
		}
	}
	return (1);
}
