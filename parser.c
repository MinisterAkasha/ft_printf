/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:40:38 by akasha            #+#    #+#             */
/*   Updated: 2020/11/21 15:40:42 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parser(t_base *base)
{
	if (*(base->src) == '*')
	{
		base->width = va_arg(base->va_tmp, int);
		(base->src)++;
		if (ft_isdigit(*(base->src)) || *(base->src))
			return (-1);
	}
	else
		base->width = ft_atoi(base->src);
	while (ft_isdigit(*(base->src)))
		++(base->src);
	if (*(base->src) == '.')
	{
		++(base->src);
		if (*(base->src) == '*')
			base->accuracy = va_arg(base->va_tmp, int);
		else if (ft_isdigit(*(base->src)))
			base->accuracy = ft_atoi(base->src);
	}
	printf("%d\n", base->width);
	printf("%d\n", base->accuracy);
	return (1);
}
