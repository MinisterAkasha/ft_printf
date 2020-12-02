/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:55:32 by akasha            #+#    #+#             */
/*   Updated: 2020/11/29 17:34:15 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_get_len(t_base *base, char *str)
{
	int len;

	len = (((int)ft_strlen(str) < base->precision) && base->has_precision) ?
		ft_strlen(str) : base->precision;
	if (base->has_precision && base->precision > 0)
		len = ((int)ft_strlen(str) < base->precision) ?
			ft_strlen(str) : base->precision;
	else
		len = ft_strlen(str);
	if (!base->precision && base->has_precision)
		len = 0;
	if (base->width > len)
		base->len_space = base->width - len;
	return (len);
}

static void	ft_write_string_whit_flag_minus
	(t_base *base, int len, char *str)
{
	write(1, str, len);
	while (base->len_space--)
	{
		write(1, " ", 1);
		base->length++;
	}
}

static void	ft_write_string_whitout_flag_minus
	(t_base *base, int len, char *str)
{
	while (base->len_space--)
	{
		write(1, " ", 1);
		base->length++;
	}
	write(1, str, len);
}

void		ft_write_string(t_base *base)
{
	char	*str;
	int		len;
	int		flag;

	flag = 0;
	str = va_arg(base->va_curr, char *);
	if (str == NULL)
	{
		flag = 1;
		str = ft_strdup("(null)");
	}
	len = ft_get_len(base, str);
	if (!base->flag_minus)
		ft_write_string_whitout_flag_minus(base, len, str);
	else if (base->flag_minus)
		ft_write_string_whit_flag_minus(base, len, str);
	else
		write(1, str, len);
	base->length += len;
	if (flag)
		free(str);
}
