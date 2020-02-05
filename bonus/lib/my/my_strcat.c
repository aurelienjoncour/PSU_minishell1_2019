/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two string
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    char *str;
    int j = 0;
    int i = 0;

    if (dest == NULL)
        return my_strdup(src);
    else {
        str = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 1));
        if (str == NULL)
            return NULL;
        my_strcpy(str, dest);
        free(dest);
    }
    for (i = my_strlen(str); src[j] != '\0'; i++) {
        str[i] = src[j];
        j++;
    }
    str[i] = '\0';
    return str;
}