/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copies n caracters of a string into another
*/
#include <stdio.h>

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int nb)
{
    int i = 0;

    while (i < nb && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
