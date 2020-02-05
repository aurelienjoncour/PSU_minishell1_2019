/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_cd
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include "word_array.h"
#include "get_env_path.h"
#include "my.h"

static int go_to_old_pwd(char ***env, int pwd, int old)
{
    char cwd[PATH_MAX];

    if (chdir((*env)[old]+7) == 0) {
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd() error");
            return 1;
        }
        free((*env)[old]);
        (*env)[old] = my_strdup("OLDPWD=");
        (*env)[old] = my_strcat((*env)[old], (*env)[pwd]+4);
        free((*env)[pwd]);
        (*env)[pwd] = my_strdup("PWD=");
        (*env)[pwd] = my_strcat((*env)[pwd], cwd);
    }
    else
        my_putstr(": No such file or directory.\n");
    return 0;
}

static int go_to_home_dir(char ***env, int pwd, int old, int home)
{
    char cwd[PATH_MAX];

    if (home == -1)
        return my_putstr("cd: No home directory.\n");
    if (chdir((*env)[home]+5) == 0) {
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd() error");
            return 1;
        }
        free((*env)[old]);
        (*env)[old] = my_strdup("OLDPWD=");
        (*env)[old] = my_strcat((*env)[old], (*env)[pwd]+4);
        free((*env)[pwd]);
        (*env)[pwd] = my_strdup("PWD=");
        (*env)[pwd] = my_strcat((*env)[pwd], cwd);
    }
    else
        my_putstr("cd: Can't change to home directory.\n");
    return 0;
}

static int go_to_path(char ***env, int pwd, int old, char *path)
{
    char cwd[PATH_MAX];

    if (chdir(path) == 0) {
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd() error");
            return 1;
        }
        free((*env)[old]);
        (*env)[old] = my_strdup("OLDPWD=");
        (*env)[old] = my_strcat((*env)[old], (*env)[pwd]+4);
        free((*env)[pwd]);
        (*env)[pwd] = my_strdup("PWD=");
        (*env)[pwd] = my_strcat((*env)[pwd], cwd);
    }
    else {
        my_putstr(path);
        my_putstr(access(path, F_OK) == 0 ?
        ": Not a directory.\n" : ": No such file or directory.\n");
    }
    return 0;
}

void recreate_env_variable(char ***env, int *pwd, int *old)
{
    char cwd[PATH_MAX];

    if (*old == -1) {
        *env = word_array_realloc(*env);
        *old = word_array_len(*env);
        (*env)[*old] = my_strdup("OLDPWD=");
    }
    if (*pwd == -1) {
        *env = word_array_realloc(*env);
        *pwd = word_array_len(*env);
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            (*env)[*pwd] = my_strcat(my_strdup("PWD="), cwd);
    }
}

int my_cd(int ac, char **av, char ***env)
{
    int pwd = getline_env_value(*env, "PWD=");
    int old = getline_env_value(*env, "OLDPWD=");
    int home = getline_env_value(*env, "HOME=");

    if (pwd == -1 || old == -1)
        recreate_env_variable(env, &pwd, &old);
    if (ac > 2)
        return my_putstr("cd: Too many arguments.\n");
    if (ac < 2)
        go_to_home_dir(env, pwd, old, home);
    else if (my_strcmp(av[1], "-") == 0)
        go_to_old_pwd(env, pwd, old);
    else
        go_to_path(env, pwd, old, av[1]);
    return 0;
}
