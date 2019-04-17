/*
** EPITECH PROJECT, 2018
** str cpy
** File description:
** desc
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int len = 0;

    for (len = 0; dest[len] != '\0'; len++);
    while (src[i] != src[nb]) {
        dest[len] = src[i];
        i++;
        len++;
    }
    dest[len] = '\0';
    return (dest);
}
