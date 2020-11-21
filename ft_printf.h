/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:16:53 by akasha            #+#    #+#             */
/*   Updated: 2020/11/21 13:16:57 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


#include <stdio.h> //!DELETE

#include <stdarg.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct 	s_base
{
	char		*src;
	int			length;
	char		*print;
	va_list		va_tmp;
	int			width;//* ширина
	int 		accuracy;//* точность
	int			i;
	char		flags[9];
}               t_base;

int ft_printf(const char *src, ...);
int	parser(t_base *base);

#endif
// "123 %d Hello %с"

// t_list->type = function(type_of_atg);
// va_start(arg, src);

// char str;
// if (t_list->*src == %)
// {
// 	t_list->src++;
// 	type = get_correct_type(*t_list->*src);
// 	va_arg(t_list->va_tmp, char);
// }

// void	get_correct_type(ch)
// {
// 	void type;
// 	if (ch == d || ch == i)
// 		(int)t_list->type;
// 	else if (ch == c)
// 		(char)t_list->type;
// }
