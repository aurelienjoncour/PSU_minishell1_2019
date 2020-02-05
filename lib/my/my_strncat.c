/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** concatenates two string till n
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);
    int j = 0;

    dest[i] = 0;
    while (j < nb && j < my_strlen(src)) {
        dest[i] = src[j];
        i++;
        j++;
    }
    return (dest);
}
