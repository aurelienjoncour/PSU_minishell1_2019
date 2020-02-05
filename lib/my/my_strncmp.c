/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** like my_strcmp but til n caracters
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1, char const *s2, int nb)
{
    int i = 0;

    while (i < nb && (s1[i] != '\0' || s2[i] != '\0')) {
        if (s1[i] < s2[i])
            return (s1[i] - s2[i]);
        else if (s1[i] > s2[i])
            return (s1[i] - s2[i]);
        else
            i++;
    }
    return (0);
}
