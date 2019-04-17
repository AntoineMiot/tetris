/*
** EPITECH PROJECT, 2018
** str cpy
** File description:
** desc
*/

char *my_revstr(char *str)
{
    int len = 0;
    int x;
    int i = 0;
    char char_stock;


    while (str[len] != '\0')
        len++;
    x = len/2;
    while (i != x) {
        char_stock = str[i];
        str[i] = str[len - 1];
        str[len - 1] = char_stock;
        i++;
        len++;
    }
    return (str);
}