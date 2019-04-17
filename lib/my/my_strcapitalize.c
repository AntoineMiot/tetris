/*
** EPITECH PROJECT, 2018
** my_strcapitalize
** File description:
** deed
*/

int up(char c)
{
    if (c >= 65 && c <= 90) {
        return (1);
    } else {
        return (0);
    }
}

int low(char c)
{
    if (c >= 97 && c <= 122) {
        return (1);
    } else {
        return (0);
    }
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    while (str[i] != '\0') {
        if (low(str[i]) == 1 && low(str[i - 1]) == 0 
                && up(str[i - 1]) == 0) {
            str[i] = str[i] - 32;
        } else if (up(str[i]) == 1 && str[i - 1] != 32) {
            str[i] = str[i] + 32;
        }
        i++;
    }
    if (low(str[0]) == 1) {
        str[0] = str[0] - 32;
    }
    return (str);
}
