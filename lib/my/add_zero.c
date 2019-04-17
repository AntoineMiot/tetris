/*
** EPITECH PROJECT, 2018
** inifin_add
** File description:
** add infini number
*/
#include <stdlib.h>

int my_strlen(char const *str);

char *add_zero(char *nb1, char *nb2)
{
    int len_big = 0;
    int len_small = 0;
    char *small_nb;

    if (my_strlen(nb1) >= my_strlen(nb2)) {
        len_big = my_strlen(nb1);
        len_small = my_strlen(nb2);
        small_nb = nb2;
    }
    else {
        len_big = my_strlen(nb2);
        len_small = my_strlen(nb1);
        small_nb = nb1;
    }
    char *new_nb = malloc(sizeof(char) * len_big);
    for (int i = 0; i <= len_big - len_small - 1; i++)
        new_nb[i] = '0';
    for (int i = len_big - len_small; i < len_big; i++)
        new_nb[i] = small_nb[i - (len_big - len_small)];
    return (new_nb);
}
