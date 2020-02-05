/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "get_next_line.h"
#include "get_bin_path.h"
#include "my.h"
#include "minishell.h"
#include "builtins.h"
#include "word_array.h"
#include "builtins_t.h"

const int nb_builtins = 4;

const builtins_t built[] = {
    { "cd", my_cd},
    { "setenv", my_setenv},
    { "unsetenv", my_unsetenv},
    { "env", my_env},
};

void my_puterror(char const *str)
{
    if (my_strlen(str) == 0)
        return;
    my_putstr(str);

    my_putstr(": Command not found.\n");
}

bool check_builtins(char ***env, char **double_tab)
{
    int ac = word_array_len(double_tab);

    for (int i = 0; i < nb_builtins; i++)
        if (my_strcmp(double_tab[0], built[i].builtins) == 0) {
            built[i].fct(ac, double_tab, env);
            return true;
        }
    return false;
}

int interprate_command(char ***env_dup, char **av, char *str)
{
    char *filepath_bin;

    if (!check_builtins(env_dup, av) && my_strlen(av[0]) != 0) {
        filepath_bin = get_bin_path(av[0], *env_dup);
        if (filepath_bin != NULL) {
            free(av[0]);
            av[0] = filepath_bin;
            minishell1(av, *env_dup);
        }
        else
            my_puterror(av[0]);
    }
    free_2d_array(av);
    free(str);
    return 0;
}

int c_flag(int ac, char **av, char **env)
{
    char **double_tab;
    char **env_dup;
    char *str;

    if (!my_strcmp(av[1], "-c")) {
        if (ac == 3) {
            str = my_strdup(av[2]);
            env_dup = word_array_dup(env);
            double_tab = my_str_to_word_array(str, " \t");
            if (my_strcmp(double_tab[0], "exit") == 0)
                return my_exit(double_tab, env_dup, str);
            interprate_command(&env_dup, double_tab, str);
            free_2d_array(env_dup);
        }
        else
            return 1;
    }
    else
        return 1;
    return 0;
}

int main(int ac, char **av, char **env)
{
    char *str;
    char **double_tab;
    char **env_dup;

    if (ac != 1)
        return c_flag(ac, av, env);
    env_dup = word_array_dup(env);
    while (1) {
        if (isatty(STDIN_FILENO))
            my_putstr("$> ");
        str = get_next_line(0);
        if (str == NULL)
            break;
        double_tab = my_str_to_word_array(str, " \t");
        if (my_strcmp(double_tab[0], "exit") == 0)
            return my_exit(double_tab, env_dup, str);
        interprate_command(&env_dup, double_tab, str);
    }
    free_2d_array(env_dup);
    return 0;
}
