/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** task04/Day06
*/
#include <unistd.h>

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int diff = my_strlen(s1) - my_strlen(s2);
    return (diff);
}
