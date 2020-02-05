/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** get_env_path
*/

#include <stdlib.h>
#include "my.h"

int getline_env_value(char **env, char *line)
{
    for (int i = 0; env[i] != NULL; i++)
        if (!my_strncmp(line, env[i], my_strlen(line)))
            return i;
    return -1;
}

char **get_env_path(char **env)
{
    int i = getline_env_value(env, "PATH=");
    char **path = NULL;

    if (i < 0)
        return NULL;
    path = my_str_to_word_array(env[i]+5, ":");
    return path;
}