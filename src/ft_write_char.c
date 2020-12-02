/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:21:48 by akasha            #+#    #+#             */
/*   Updated: 2020/11/29 14:43:59 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_write_char(t_base *base)
{
	char ch;

	ch = va_arg(base->va_curr, int);
	if (base->width && base->flag_minus)
	{
		write(1, &ch, 1);
		while (base->width-- > 1)
		{
			write(1, " ", 1);
			base->length++;
		}
	}
	else if (base->width)
	{
		while (base->width-- > 1)
		{
			write(1, " ", 1);
			base->length++;
		}
		write(1, &ch, 1);
	}
	else
		write(1, &ch, 1);
	base->length++;
}
