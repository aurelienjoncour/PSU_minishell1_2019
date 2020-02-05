/*
** EPITECH PROJECT, 2019
** my_showstr.c
** File description:
** returns 1 if the string passed as parameters only contanis printable char
*/

void my_putchar(char c);

static int my_char_isprintable(char const c)
{
    if (c > 31 && c < 127)
        return (1);
    else
        return (0);
}

int my_showstr(char const *str)
{
    char tab[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'a', 'b', 'c', 'd', 'e', 'f'};

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isprintable(str[i]))
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            my_putchar(tab[str[i] / 16]);
            my_putchar(tab[str[i] % 16]);
        }
    }
    return (0);
}
