/*
** EPITECH PROJECT, 2018
** swap
** File description:
** swap to integer
*/

int my_strlen(char const *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return (i);
}