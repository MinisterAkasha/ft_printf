/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:17:47 by akasha            #+#    #+#             */
/*   Updated: 2020/12/02 20:44:46 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <stdio.h>

static void	ft_write_pointer_parser(t_base *base, int len, int check_null)
{
	if (base->flag_minus == 1)
	{
		write(1, "0x", 2);
		ft_write_number(base, 'p');
		base->length += 2;
	}
	else if (!base->flag_minus)
	{
		while (base->width > len)
		{
			write(1, " ", 1);
			base->length++;
			base->width--;
		}
		write(1, "0x", 2);
		base->length += 2;
		if (check_null)
			return ;
		ft_write_number(base, 'p');
	}
}

void		ft_write_pointer(t_base *base)
{
	int		len;
	char	*str;
	int		check_null;

	base->width -= 2;
	check_null = 0;
	va_copy(base->va_copy, base->va_curr);
	va_copy(base->va_copy_cur, base->va_curr);
	if (va_arg(base->va_curr, void *) == NULL && base->has_precision)
	{
		check_null = 1;
		str = ft_strdup("");
		len = 0;
	}
	else
	{
		str = ft_itoa_hex(va_arg(base->va_copy, size_t), 16, 'x');
		len = ft_strlen(str);
	}
	free(str);
	ft_write_pointer_parser(base, len, check_null);
}
