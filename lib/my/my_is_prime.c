/*
** EPITECH PROJECT, 2018
** my_compute_factorial_rec
** File description:
** 
*/

int my_is_prime(int nb)
{
    if (nb <= 1) {
        return (0);
    }
    if (nb % 2 == 0 && nb > 2) {
        return (0);
    }
    for (int i = 3; i < nb/2; i = i + 2) {
        if (nb % i == 0) {
            return (0);
        }
    }
    return (1);
}
