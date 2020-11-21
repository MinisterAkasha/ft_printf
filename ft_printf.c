/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:16:41 by akasha            #+#    #+#             */
/*   Updated: 2020/11/21 13:16:45 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //!DELETE
#include <string.h> //!DELETE

char    *ft_strjoin_char(char *str, int ch)
{
	char	*s1;
	int 	i;
	int		len;

	i = 0;
	if (!str || !ch)
		return (0);
	len = ft_strlen(str);
	if (!(s1 = (char *)malloc(sizeof(char) * len + 2)))
		return (0);
	while (i < (int)len)
	{
		s1[i] = str[i];
		i++;
	}
	s1[i++] = ch;
	s1[i] = 0;
	return (s1);
}

void    ft_write_char(t_base *base)
{
	char    tmp;
	char    *copy;

	tmp = va_arg(base->va_tmp, int);
	copy = base->print;
	base->print = ft_strjoin_char(copy, tmp);
	free(copy);
}

void     ft_write_int(t_base *base)
{
	char    *number;
	char    *copy;

	number = ft_itoa(va_arg(base->va_tmp, int));
	copy = base->print;
	base->print = ft_strjoin(copy, number);
	free(copy);
}

int 	get_correct_type(t_base *base)
{
	char	ch;

	parser(base);
	ch = *(base->src);
	if (ch == 'c')
		ft_write_char(base);
	else if (ch == 'd' || ch == 'i')
		ft_write_int(base);
	// else if (ch == 's')
	//     ft_write_string(base);
	// else if (ch == 'p')
	//     ft_write_pointer(base);
	// else if (ch == 'u')
	//     ft_write_unsigned_int(base);
	// else if (ch == 'x')
	//     ft_write_lower_hex(base);
	// else if (ch == 'X')
	//     ft_write_upper_hex(base);
	// else if (ch == '%')
	//     ft_write_percent(base);
	else
		return (-1);
	return (1);
}



int    work(t_base *data_base)
{
	char    *copy;
	char    ch;
	int     len;

	len = ft_strlen(data_base->src);
	data_base->print = ft_strdup("");
	while (*(data_base->src))
	{
		if (*(data_base->src) == '%')
		{
			(data_base->src)++;
			if (get_correct_type(data_base) == -1)
				return (-1);
		}
		else
		{
			ch = (*(data_base->src));
			copy = data_base->print;
			data_base->print = ft_strjoin_char(copy, ch);
			free(copy);
		}
		++(data_base->src);
	}
	data_base->length = ft_strlen(data_base->print); //? LENGTH OF PRINTABLE STRING
	// printf("%s", data_base->print);
	free(data_base->print); //TODO DONT FORGET ABOUT THIS FREE
	return (1);
}

int ft_printf(const char *src, ...)
{
	t_base  *data_base;

	if (!(data_base = (t_base *)malloc(sizeof(t_base))))
		return (-1);
	data_base->src = (char *)src;
	if (src)
	{
		va_start(data_base->va_tmp, src);
		if (work(data_base) == -1)
			return (-1);
		va_end(data_base->va_tmp);
	}
	write(1, data_base->print, data_base->length);
	free(data_base);
	return (data_base->length);
}
