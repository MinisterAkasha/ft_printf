#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>

typedef struct 	s_base
{
	char		*src;
	int			length;
	char		*print;
	va_list		va_tmp;
	void		*type;
}               t_base;

int ft_printf(const char *src, ...);

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