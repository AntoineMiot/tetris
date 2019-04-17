/*
** EPITECH PROJECT, 2018
** my_compute_factorial_rec
** File description:
** 
*/

int my_compute_power_rec(int nb, int p)
{
    int result = nb;
    int range = p;

    if (p == 0) {
        return (1);
    }
    else if (p < 0) {
        return (0);
    }
    else {
        result = result * my_compute_power_rec(nb, range - 1);
        return (result);
    }
}