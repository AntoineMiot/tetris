/*
** EPITECH PROJECT, 2018
** sum_stdarg
** File description:
** additionne tous les int que l'on rentre en argument
*/
#include <stdarg.h>
#include <stdio.h>

int my_strlen(char const *str);

int sum_stdarg_int(int nb, va_list ap)
{
    int n;
    int count = 0;

        for (nb; nb > 0; nb--) {
            n = va_arg(ap, int);
            count = count + n;
        }
    va_end(ap);
    return (count);
}

int sum_stdarg_char(int nb, va_list ap)
{
    char const *n;
    int count = 0;

        for (nb; nb > 0; nb--) {
            n = va_arg(ap, char const *);
            count = count + my_strlen(n);
        }
    va_end(ap);
    return (count);
}

int sum_stdarg(int i, int nb, ...)
{
    va_list ap;
    va_start(ap, nb);

    if (i == 0)
        return (sum_stdarg_int(nb, ap));
    if (i == 1)
        return (sum_stdarg_char(nb, ap));
}