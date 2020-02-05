/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** builtins_t
*/

#ifndef BUILTINS_T_H_
#define BUILTINS_T_H_

typedef struct {
    char *builtins;
    int (*fct)(int ac, char **av, char ***env);
}builtins_t;

#endif /* !BUILTINS_T_H_ */
