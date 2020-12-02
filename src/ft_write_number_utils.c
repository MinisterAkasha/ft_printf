/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:18:58 by akasha            #+#    #+#             */
/*   Updated: 2020/11/29 17:25:19 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_write_precision(t_base *base, double number, int len, char *str)
{
	if (base->len_zero && number < 0)
		write(1, str++, 1);
	while (base->len_zero-- > 0)
	{
		write(1, "0", 1);
		base->length++;
	}
	write(1, (str), len);
}

void	ft_write_number_without_flags
	(t_base *base, double number, int len, char *str)
{
	while (base->len_space-- > 0)
	{
		write(1, " ", 1);
		base->length++;
	}
	if (base->len_zero && number < 0)
		write(1, str++, 1);
	while (base->len_zero-- > 0)
	{
		write(1, "0", 1);
		base->length++;
	}
	write(1, (str), len);
}

void	ft_write_number_whith_flag_minus
	(t_base *base, double number, int len, char *str)
{
	if (base->len_zero && number < 0)
		write(1, str++, 1);
	while (base->len_zero-- > 0)
	{
		write(1, "0", 1);
		base->length++;
	}
	write(1, (str), len);
	while (base->len_space-- > 0)
	{
		write(1, " ", 1);
		base->length++;
	}
}

void	ft_write_number_whith_flag_zero
	(t_base *base, double number, int len, char *str)
{
	while (base->len_space-- > 0)
	{
		write(1, " ", 1);
		base->length++;
	}
	if (base->len_zero && number < 0)
		write(1, str++, 1);
	while (base->len_zero-- > 0)
	{
		write(1, "0", 1);
		base->length++;
	}
	write(1, (str), len);
}
