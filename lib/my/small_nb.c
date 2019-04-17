/*
** EPITECH PROJECT, 2018
** inifin_add
** File description:
** add infini number
*/

int my_strlen(char const *str);

char *small_nb(char *nb1, char *nb2)
{
    if (my_strlen(nb1) > my_strlen(nb2))
        return (nb2);
    else if (my_strlen(nb2) > my_strlen(nb1))
        return (nb1);
    for ( int i = 0; nb1[i] != '\0'; i++ ) {
        if ( nb1[i] > nb2[i] )
            return (nb2);
        if ( nb2[i] > nb1[i] )
            return (nb1);
    }
    return (nb2);
}
