/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** returns a number sent to the function as a string
*/

#include <limits.h>

int my_strlen(char const *str);

int my_put_nbr(int nb);

static int it_is_neg(char const *str, int len, int *start)
{
    int neg = 1;

    while (*start < len && !(str[*start] >= '0' && str[*start] <= '9')) {
        if (str[*start] == '-')
            neg = neg * -1;
        *start = *start + 1;
    }
    return (neg);
}

static int too_fit(int start, int end)
{
    if ( end - start > 10)
        return (1);
    return (0);
}

static int my_char_isalpha(char const c)
{
    if ((c >= 'A' && c <= 'Z' ) || (c >= 'a' && c <= 'b'))
        return (0);
    return 1;
}

static long check_too_long(long nb)
{
    if (nb > INT_MAX || nb < INT_MIN)
        return (0);
    return (nb);
}

int my_getnbr(char const *str)
{
    int start = 0;
    int end = 0;
    long nb = 0;
    int dix = 1;
    int neg = it_is_neg(str, my_strlen(str), &start);

    end = start;
    if (my_char_isalpha(str[0]) == 0)
        return (0);
    while (end < my_strlen(str) && (str[end] >= '0' && str[end] <= '9'))
        end++;
    if (too_fit(start, end) != 0)
        return (0);
    end--;
    while (end >= start) {
        nb += (str[end] - 48) * dix;
        dix *= 10;
        end--;
    }
    return ((int) check_too_long(nb *= neg));
}
