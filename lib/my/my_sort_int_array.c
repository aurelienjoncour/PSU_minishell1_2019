/*
** EPITECH PROJECT, 2019
** my_sort_int_array.c
** File description:
** sorts an integers array in ascending order
*/

void my_swap(int *a, int *b);

void my_sort_int_array(int *tab, int size)
{
    int i = 1;
    int j = 0;
    int var = 0;

    while (i  < size) {
        var = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > var) {
            my_swap(&tab[j], &tab[j+1]);
            j = j -1;
        }
        i++;
    }
}
