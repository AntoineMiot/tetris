/*
** EPITECH PROJECT, 2018
** infin_add
** File description:
** infin_add
*/

int my_strlen(char const *str);

int my_str_is_equal(char *str1, char *str2)
{
    int len_1 = my_strlen(str1);
    int len_2 = my_strlen(str2);

    if ( len_1 != len_2 )
        return (0);
    for ( int i = 0; str1[i] != '\0'; i++ )
        if ( str1[i] != str2[i] )
            return (0);
    return (1);
}
