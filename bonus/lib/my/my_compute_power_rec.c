/*
** EPITECH PROJECT, 2019
** my_compute_power_rec.c
** File description:
** recursive functions that returns the first arguments to the power of the nd
*/

int my_compute_power_rec(int nb, int power)
{
    if (power == 0)
        return (1);
    if (power < 0)
        return (0);
    while (power > 1)
    {
        return (nb * my_compute_power_rec(nb, power - 1));
    }
    return (nb);
}
