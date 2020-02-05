/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** capitalizes the first letter of each word
*/

int my_strlen(char const *str);

static int is_it_alphanum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (2);
    if (c >= 'A' && c <= 'Z')
        return (3);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    if (is_it_alphanum(str[0]) == 2)
        str[0] -= 32;
    while (i < my_strlen(str)) {
        if (is_it_alphanum(str[i - 1]) > 0 && is_it_alphanum(str[i]) == 3 )
            str[i] += 32;
        if (is_it_alphanum(str[i - 1]) == 0 && is_it_alphanum(str[i]) == 2 )
            str[i] -= 32;
        i++;
    }
    return (str);
}
