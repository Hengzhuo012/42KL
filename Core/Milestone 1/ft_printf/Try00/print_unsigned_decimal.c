/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zheng <zheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 23:20:21 by zheng             #+#    #+#             */
/*   Updated: 2026/08/03 23:23:25 by zheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
(mode 0)
%u

(mode 1)
%-(width)u -> padding with leading ' ', left-aligned
				only if width > widthgth else ignore
				overwrite 0 flag

(mode 2)
%(width)u -> padding with ending ' ', right-aligned
				only if width > widthgth else ignore

(mode 3)
%0(width)u -> padding with leading '0', right-aligned
				only if width > widthgth else ignore

(precision)
%.(precision)u -> min number of digits to output
					ignore flag 0 if exsists
					%.0u, u = 0, output = (empty)
*/