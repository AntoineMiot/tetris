/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** task04/Day06
*/
#include <unistd.h>

int my_strlen(char const *str);

int my_str_taller(char const *s1, char const *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    if (len1 >= len2)
        return (len2);
    else
        return (len1);
}
