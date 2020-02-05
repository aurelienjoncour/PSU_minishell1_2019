/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** get_bin_path
*/

#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "get_env_path.h"
#include "word_array.h"

static char *cat_filepath(char *filepath_bin, char *env_path, char *binary_name)
{
    free(filepath_bin);
    filepath_bin = my_strdup(env_path);
    filepath_bin = my_strcat(filepath_bin, "/");
    filepath_bin = my_strcat(filepath_bin, binary_name);
    return filepath_bin;
}

char *free_env(char **env_path)
{
    free_2d_array(env_path);
    return NULL;
}

bool filepath_valid(char *filepath_bin, int stat_return)
{
    if (stat_return == -1) {
        free(filepath_bin);
        return false;
    }
    return true;
}

char *get_bin_path(char *binary_name, char **env)
{
    char **env_path = get_env_path(env);
    int stat_return = -1;
    char *filepath_bin = NULL;

    if (my_strchr(binary_name, '/') && access(binary_name, F_OK) == 0) {
        free_2d_array(env_path);
        return my_strdup(binary_name);
    }
    if (env_path == NULL)
        return free_env(env_path);
    filepath_bin = my_strdup(binary_name);
    for (int i = 0; stat_return == -1 && env_path[i] != NULL; i++) {
        filepath_bin = cat_filepath(filepath_bin, env_path[i], binary_name);
        stat_return = access(filepath_bin, F_OK);
    }
    free_2d_array(env_path);
    if (!filepath_valid(filepath_bin, stat_return))
        return NULL;
    return filepath_bin;
}