/*
** EPITECH PROJECT, 2019
** my_find_prime_sup
** File description:
** return the plus super proche prime number
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) != 1)
        nb++;
    return (nb);
}
