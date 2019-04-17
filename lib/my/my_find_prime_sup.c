/*
** EPITECH PROJECT, 2018
** my_compute_factorial_rec
** File description:
** 
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

int my_find_prime_sup(int nb)
{
    if (nb < 0) {
        return (2);
    }
    int verif = my_is_prime(nb);

    if (verif == 1) {
        return (nb);
    }
    else {
        nb = my_find_prime_sup(nb+1);
        return (nb);
    }
}
