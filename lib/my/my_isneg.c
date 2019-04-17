/*
** EPITECH PROJECT, 2018
** my_print_alpha
** File description:
** print the lowercase alphabet
*/

void my_putchar(char c);

void my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    }
    else {
        my_putchar('P');
    }
}
