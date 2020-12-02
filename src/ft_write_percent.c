/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:55:39 by akasha            #+#    #+#             */
/*   Updated: 2020/11/29 17:34:19 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_write_percent_with_flag_minus(t_base *base)
{
	write(1, "%", 1);
	while (base->width-- > 1)
	{
		base->length++;
		write(1, " ", 1);
	}
}

static void	ft_write_percent_without_flag_minus(t_base *base)
{
	while (base->width-- > 1)
	{
		base->length++;
		write(1, "0", 1);
	}
	write(1, "%", 1);
}

void		ft_write_percent(t_base *base)
{
	if (base->width)
	{
		if (base->flag_minus)
			ft_write_percent_with_flag_minus(base);
		else if (base->flag_zero)
			ft_write_percent_without_flag_minus(base);
		else
		{
			while (base->width-- > 1)
			{
				base->length++;
				write(1, " ", 1);
			}
			write(1, "%", 1);
		}
	}
	else
		write(1, "%", 1);
	base->length++;
}
