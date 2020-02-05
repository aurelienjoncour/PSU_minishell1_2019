/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** word_array
*/

#ifndef WORD_ARRAY_H_
#define WORD_ARRAY_H_

void free_2d_array(char **array);

int word_array_len(char **array);

char **word_array_dup(char **env);

char **word_array_realloc(char **env);

#endif /* !WORD_ARRAY_H_ */