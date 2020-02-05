/*
** EPITECH PROJECT, 2019
** my_is_prime.c
** File description:
** return 1 if the number is prime and 0 if not
*/

static int square_root(int nb)
{
    int i = 1;

    while (i * i < nb){
        if (i == 46340)
            return (i);
        i++;
    }
    return (i);
}

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 1)
        return (0);
    if (nb == 2)
        return (1);
    while (i <= square_root(nb)) {
        if (nb % i == 0) {
            return (0);
        }
        i++;
    }
    return (1);
}
