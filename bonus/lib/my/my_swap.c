/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swap the content of two integers
*/

void my_swap(int *a, int *b)
{
    int tmp = *a;

    *a = *b;
    *b = tmp;
}
