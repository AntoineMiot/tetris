/*
** EPITECH PROJECT, 2018
** swap
** File description:
** swap to integer
*/

void my_swap(int *a, int *b)
{
    int p;

    p = *a;
    *a = *b;
    *b = p;
}