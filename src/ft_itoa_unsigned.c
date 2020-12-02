/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:32:33 by akasha            #+#    #+#             */
/*   Updated: 2020/11/29 14:43:36 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static long	ft_numlen(unsigned int num)
{
	int		ln;

	ln = 0;
	if (num <= 0)
		ln = 1;
	while (num)
	{
		num /= 10;
		ln++;
	}
	return (ln);
}

char		*ft_itoa_unsigned(unsigned int n)
{
	int		ln;
	char	*str;

	ln = ft_numlen(n);
	if (!(str = (char *)malloc(sizeof(char) * ln + 1)))
		return (0);
	str += ln;
	*str-- = '\0';
	if (!n)
		*str = '0';
	while (n)
	{
		*str = (n % 10) + 48;
		if (n > 9)
			str--;
		n /= 10;
	}
	return (str);
}
