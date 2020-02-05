/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** return 0 if string are the same or other number if the string are differents
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] < s2[i])
            return (s1[i] - s2[i]);
        else if (s1[i] > s2[i])
            return (s1[i] - s2[i]);
        else
            i++;
    }
    return (0);
}
