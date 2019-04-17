/*
** EPITECH PROJECT, 2018
** my_compute_factorial_rec
** File description:
** 
*/

int my_compute_square_root(int nb)
{
    int result = 0;
    int i = 0;

    if (nb < 0) {
        return (0);
    }
    while (result != nb && result < nb) {
        i++;
        result = i * i;
    }
    if (nb == i * i) {
        return (i);
    }
    else {
        return (0);
    }
}