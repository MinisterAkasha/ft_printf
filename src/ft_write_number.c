/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:41:30 by akasha            #+#    #+#             */
/*   Updated: 2020/12/02 20:30:25 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

double	ft_write_number_parser(char **str, char ch, t_base *base)
{
	double number;

	number = 0;
	if (ch == 'i' || ch == 'd')
	{
		number = va_arg(base->va_curr, int);
		*str = ft_itoa(number);
	}
	else if (ch == 'u')
	{
		number = va_arg(base->va_curr, unsigned int);
		*str = ft_itoa_unsigned(number);
	}
	else if (ch == 'x' || ch == 'X')
	{
		number = va_arg(base->va_curr, unsigned int);
		*str = ft_itoa_hex(number, 16, ch);
	}
	else if (ch == 'p')
	{
		number = va_arg(base->va_copy_cur, size_t);
		*str = ft_itoa_hex(number, 16, 'x');
	}
	return (number);
}

void	ft_get_len_space_zero(t_base *base, int len, double number)
{
	if (base->width > base->precision && base->width > len)
		base->len_space = base->precision < len ? base->width - len :
			base->width - base->precision;
	if (len < base->precision && number >= 0 && base->has_precision)
		base->len_zero = base->precision - len;
	else if (len <= base->precision && number < 0)
		base->len_zero = base->precision - len + 1;
	else if (base->flag_zero && !base->precision)
		base->len_zero = base->len_space;
	else if (base->flag_zero && base->precision && base->has_precision)
		base->len_zero = 0;
	if (number < 0 && base->len_zero)
		base->len_space--;
	if (base->flag_zero && !base->precision)
		base->len_space = 0;
	if (!base->precision && base->has_precision && base->flag_zero)
	{
		base->flag_zero = 0;
		base->len_space = base->len_zero;
		base->len_zero = 0;
	}
}

void	ft_check_flags(t_base *base, double number, int len, char *str)
{
	if (base->width < base->precision)
		ft_write_precision(base, number, len, str);
	else if (base->width >= base->precision)
	{
		if (!base->flag_minus && !base->flag_zero)
			ft_write_number_without_flags(base, number, len, str);
		else if (base->flag_minus)
			ft_write_number_whith_flag_minus(base, number, len, str);
		else if (base->flag_zero)
			ft_write_number_whith_flag_zero(base, number, len, str);
	}
	else
		write(1, (str), len);
}

void	ft_write_number(t_base *base, char ch)
{
	char	*str;
	int		len;
	double	number;

	number = ft_write_number_parser(&str, ch, base);
	if (number == 0 && !base->precision && base->has_precision)
	{
		while (base->width--)
		{
			write(1, " ", 1);
			base->length++;
		}
		free(str);
		return ;
	}
	len = ft_strlen(str);
	base->length += len;
	if (base->flag_minus == 1)
		base->flag_zero = 0;
	ft_get_len_space_zero(base, len, number);
	if (base->len_zero && number < 0)
		len--;
	base->precision = base->precision > len ? base->precision : len;
	ft_check_flags(base, number, len, str);
	free(str);
}
