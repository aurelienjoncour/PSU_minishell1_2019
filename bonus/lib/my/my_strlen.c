/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** counts and return the number of caracters of the string
*/

int my_strlen(char const *str)
{
    int leng = 0;

    while (str[leng] != '\0')
        leng++;
    return (leng);
}
