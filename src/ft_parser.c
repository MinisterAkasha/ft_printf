/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:33:39 by akasha            #+#    #+#             */
/*   Updated: 2020/12/02 20:44:54 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_parser_width(t_base *base)
{
	if (ft_isdigit(*(base->src)))
		base->width = ft_atoi(base->src);
	else if (*(base->src) == '*')
	{
		base->width = va_arg(base->va_curr, int);
		if (base->width < 0)
		{
			base->flag_minus = 1;
			base->width *= -1;
		}
		(base->src)++;
	}
}

void	ft_parser_precision(t_base *base)
{
	if (*(base->src) == '.')
	{
		base->has_precision = 1;
		++(base->src);
		if (*(base->src) == '*')
		{
			base->precision = va_arg(base->va_curr, int);
			(base->src++);
			if (base->precision < 0)
			{
				base->has_precision = 0;
				base->precision = 0;
			}
		}
		else
			base->precision = ft_atoi(base->src);
		while (ft_isdigit(*(base->src)))
			(base->src)++;
	}
}

void	ft_parser(t_base *base)
{
	if (*(base->src) == '-' || *(base->src) == '0')
	{
		while (*(base->src) == '-' || *(base->src) == '0')
		{
			if (*(base->src) == '-')
				base->flag_minus = 1;
			else
				base->flag_zero = 1;
			(base->src)++;
		}
	}
	ft_parser_width(base);
	while (ft_isdigit(*(base->src)))
		(base->src)++;
	ft_parser_precision(base);
}
