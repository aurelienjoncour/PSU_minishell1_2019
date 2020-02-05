/*
** EPITECH PROJECT, 2019
** my_strupcase.c
** File description:
** puts every letter of every word in it in uppercase
*/

int my_strlen(char const *str);

char *my_strupcase(char *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] += 'A' - 'a';
        i++;
    }
    return (str);
}
