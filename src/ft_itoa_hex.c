/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:39:24 by akasha            #+#    #+#             */
/*   Updated: 2020/11/29 18:27:51 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_numlen(unsigned long num, int base)
{
	int fl;
	int	ln;

	ln = 0;
	fl = 0;
	while (fl == 0)
	{
		num = (num / base);
		if (num == 0)
			fl = 1;
		ln++;
	}
	return (ln);
}

char		*ft_itoa_hex(unsigned long num, int base, char ch)
{
	int		ln;
	char	*str;
	char	*buf;

	ln = ft_numlen(num, base);
	if (!(str = (char *)malloc(sizeof(char) * (ln + 1))))
		return (0);
	buf = str;
	str += ln;
	*str-- = '\0';
	if (!num)
		*str = '0';
	while (num)
	{
		if (num % base > 9 && ch == 'X')
			*str = num % base + 'A' - 10;
		else if (num % base > 9 && ch == 'x')
			*str = num % base + 'a' - 10;
		else
			*str = (num % base) + 48;
		if (num > 15)
			str--;
		num /= base;
	}
	return (str);
}
