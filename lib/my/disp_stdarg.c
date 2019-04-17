/*
** EPITECH PROJECT, 2018
** sum_stdarg
** File description:
** additionne tous les int que l'on rentre en argument
*/
#include <stdarg.h>
#include <stdio.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);

int disp_stdarg(char *s, ...)
{
    va_list	ap;
    int	i = 0;

    va_start(ap, s);
    while (s[i] != '\0') {
        if (s[i] == 'c')
	        my_putchar(va_arg(ap, int));
        if (s[i] == 'i')
	        my_put_nbr(va_arg(ap, int));
        if (s[i] == 's')
	        my_putstr(va_arg(ap, char *));
        my_putchar('\n');
        i ++;
    }
    va_end(ap);
    return (0);
}