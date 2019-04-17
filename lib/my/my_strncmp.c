/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** task
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len1 = my_strlen(s1, n);
    int len2 = my_strlen(s2, n);

    return (len1 - len2);
}
