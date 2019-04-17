/*
** EPITECH PROJECT, 2018
** str cpy
** File description:
** desc
*/

char *my_strncpy(char *dest, char const *src, int nb)
{
    int i = nb;
    int j = 0;
    while (src[i] != '\0') {
        dest[j] = src[i];
        i++;
        j++;
    }
    return (dest);
}
