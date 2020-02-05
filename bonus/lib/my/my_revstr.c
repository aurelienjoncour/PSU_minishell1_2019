/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** return a reverse string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    int tmp = 0;

    while (j > i) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
    return (str);
}
