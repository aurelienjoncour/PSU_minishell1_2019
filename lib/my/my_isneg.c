/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** print N if the integer is negative P if the integer is positive or null
*/

void my_putchar(char c);

int my_isneg(int nb)
{
    if (nb < 0)
        my_putchar('N');
    else if (nb >= 0)
        my_putchar('P');
    return (0);
}
