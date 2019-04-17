/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** deed
*/

int my_strlen(char const *str);

int my_str_isnum(char *str)
{
    int len = my_strlen(str);
    int count = 0;
    int i = 0;

    if (len == 0) {
        return (1);
    }
    while (str[i] != '\0') {
        if (str[i] <= 57 && str[i] >= 48) {
            count++;
        }
        i++;
    }
    if (count == len)
        return (1);
    else
        return (0);
}
