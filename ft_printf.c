#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

void    work(t_base *data_base)
{
    // char    ch;
    char    *copy;
    char    str;


    while (data_base->src)
    {
        str = *(data_base->src);
        copy = data_base->print;
        data_base->print = strjoin(data_base->print, (char *)*(data_base->src));
        free(copy);
    }
    // data_base->type = get_correct_type('c' ,data_base);
    // va_arg(data_base->va_tmp, data_base->type);
}

// void	get_correct_type(char ch, t_base base)
// {
// 	if (ch == 'd' || ch == 'i')
// 		((int)base.type);
// 	else if (ch == 'c')
// 		((char)base.type);
// }

int ft_printf(const char *src, ...)
{
    t_base  *data_base;

    if (!(data_base = (t_base *)malloc(sizeof(t_base))))
        return (-1);
    data_base->src = (char*)src;
    if (src)
    {
        va_start(data_base->va_tmp, src);
        work(data_base);
        va_end(data_base->va_tmp);
    }
    free (data_base);
    return (data_base->length);
}
