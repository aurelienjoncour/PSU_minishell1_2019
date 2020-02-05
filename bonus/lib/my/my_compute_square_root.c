/*
** EPITECH PROJECT, 2019
** my_compute_square_root.c
** File description:
** return the square root if it is a whole number
*/

int my_compute_square_root(int nb)
{
    int i = 1;
    int tmp = nb/2;

    while (i * i < nb && i <= tmp) {
        i++;
    }
    if (i * i == nb)
        return (i);
    return (0);
}
