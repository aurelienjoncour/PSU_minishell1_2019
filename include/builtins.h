/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** builtins
*/

#ifndef BUILTINS_H_
#define BUILTINS_H_

int my_cd(int ac, char **av, char ***env);

void put_error_cd(char *path);

int my_setenv(int ac, char **av, char ***env);

int my_unsetenv(int ac, char **av, char ***env);

int my_env(int ac, char **av, char ***env);

char my_exit(char **av, char **env_dup, char *str);

#endif /* !BUILTINS_H_ */
