/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasha <akasha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:16:53 by akasha            #+#    #+#             */
/*   Updated: 2020/11/29 18:50:39 by akasha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_base
{
	char		*src;
	long int	length;
	va_list		va_curr;
	va_list		va_copy;
	va_list		va_copy_cur;
	int			width;
	int			precision;
	int			has_precision;
	int			flag_minus;
	int			flag_zero;
	int			len_zero;
	int			len_space;
}				t_base;

int				ft_printf(const char *src, ...);

void			ft_parser(t_base *base);
void			ft_parser_precision(t_base *base);
void			ft_parser_width(t_base *base);

void			ft_reset(t_base *data_base);

void			ft_write_char(t_base *base);
void			ft_write_string(t_base *base);
void			ft_write_unsigned_int(t_base *base);

char			*ft_itoa_hex(size_t num, int base, char ch);
char			*ft_itoa_unsigned(unsigned int n);

void			ft_write_percent(t_base *base);
void			ft_write_pointer(t_base *base);

void			ft_write_number(t_base *base, char ch);
double			ft_write_number_parser(char **str, char ch, t_base *base);
void			ft_write_precision
				(t_base *base, double number, int len, char *str);
void			ft_write_number_without_flags
				(t_base *base, double number, int len, char *str);
void			ft_write_number_whith_flag_minus
				(t_base *base, double number, int len, char *str);
void			ft_write_number_whith_flag_zero
				(t_base *base, double number, int len, char *str);

#endif
