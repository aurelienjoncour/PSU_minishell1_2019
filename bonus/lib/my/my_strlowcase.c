/*
** EPITECH PROJECT, 2019
** my_strlowcase
** File description:
** put every letter of every word in lowercase
*/

int my_strlen(char const *str);

char *my_strlowcase(char *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
        i++;
    }
    return (str);
}
