/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:16:41 by akasha            #+#    #+#             */
/*   Updated: 2020/11/29 18:04:09 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	get_correct_type(t_base *base)
{
	char	ch;

	ft_parser(base);
	ch = *(base->src);
	if (ch == 'c')
		ft_write_char(base);
	else if (ch == 'd' || ch == 'i' || ch == 'x'
		|| ch == 'X' || ch == 'u')
		ft_write_number(base, ch);
	else if (ch == 's')
		ft_write_string(base);
	else if (ch == 'p')
		ft_write_pointer(base);
	else if (ch == '%')
		ft_write_percent(base);
}

int		read_input(t_base *data_base)
{
	while (*(data_base->src))
	{
		if (*(data_base->src) == '%')
		{
			++(data_base->src);
			get_correct_type(data_base);
			ft_reset(data_base);
		}
		else
		{
			write(1, &(*(data_base->src)), 1);
			(data_base->length)++;
		}
		++(data_base->src);
	}
	return (1);
}

void	ft_reset(t_base *base)
{
	base->flag_minus = 0;
	base->flag_zero = 0;
	base->width = 0;
	base->has_precision = 0;
	base->precision = 0;
	base->len_zero = 0;
	base->len_space = 0;
}

int		ft_printf(const char *src, ...)
{
	t_base	*data_base;
	int		length;

	if (!(data_base = (t_base *)malloc(sizeof(t_base))))
		return (-1);
	data_base->length = 0;
	data_base->src = (char *)src;
	ft_reset(data_base);
	if (src)
	{
		va_start(data_base->va_curr, src);
		read_input(data_base);
		va_end(data_base->va_curr);
	}
	length = data_base->length;
	free(data_base);
	return (length);
}
