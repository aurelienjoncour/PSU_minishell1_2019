/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocate memory and copies the given string in argument
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(const char *src)
{
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL)
        return NULL;
    return (my_strcpy(str, src));
}