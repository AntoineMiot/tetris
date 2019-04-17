/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** get the number in a string
*/

int use_strlen_task05(char const *str)
{
    int i;
    int number;

    i = 0;
    number = 0;
    while (str[i] > '\0') {
        i = i + 1;
        number = number + 1;
    }
    return (number);
}

int is_nega(const char *str, int neg)
{
    int nb_inside = 0;

    while (str[neg - 1] == '-') {
        nb_inside = nb_inside + 1;
        neg = neg - 1;
    }
    if (nb_inside % 2 == 1)
        return 1;
    return 0;
}

int change_char_in(char *str,const char *list, int neg)
{
    int length = use_strlen_task05(str);
    int rtrn = 0;
    long number_test = 0;
    int i, nega;
    int power = 1;

    if (length <= 10) {
        for (i = length - 1; i >= 0; i = i - 1) {
            number_test = number_test + (power * (str[i] - 48));
            power = power * 10;
        }
    } else {
        rtrn = 0;
    }
    nega = is_nega(list, neg);
    if (number_test > 2147483647 || (-number_test < -2147483648 && nega == 1))
        return 0;
    rtrn = number_test;
    return (rtrn);
}

int get_return(char *new, const char *str,int v1, int *neg)
{
    int rtrn, i;
    int nb_inside = 0;
    int lenght = use_strlen_task05(str);

    i = 0;
    while (v1 != 2 && i < lenght) {
        if (str[i] >= '0' && str[i] <= '9') {
            if (v1 == 0)
                *neg = i;
            v1 = 1;
            new[nb_inside] = str[i];
            nb_inside = nb_inside + 1;
        }
        if ((str[i] < '0' || str[i] > '9') && v1 == 1)
            v1 = 2;
        i = i + 1;
    }
    new[nb_inside] = '\0';
    rtrn = change_char_in(new, str, *neg);
    return (rtrn);
}

int my_getnbr(char const *str)
{
    int len = use_strlen_task05(str);
    char new[len];
    int nb_inside = 0;
    int verif1 = 0;
    int nega = 1;
    int i = 1;
    int rtrn;

    rtrn = get_return(new, str, verif1, &nega);
    while (str[nega - 1] == '-') {
        nb_inside = nb_inside + 1;
        nega = nega - 1;
    }
    if (nb_inside % 2 == 1)
        rtrn = -1 * rtrn;
    return (rtrn);
}
