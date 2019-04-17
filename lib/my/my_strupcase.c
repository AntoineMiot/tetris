/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** task04/Day06
*/
#include <unistd.h>

int my_strlen(char const *str);

char *my_strupcase(char *str)
{
    int len = my_strlen(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 97 || str[i] <= 122) {
            str[i] = str[i] - 32;
        }
    }
    return (str);
}
