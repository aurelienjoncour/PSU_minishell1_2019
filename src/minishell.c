/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** minishell
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "my.h"
#include "error.h"

void process_error(int status)
{
    if (!WIFEXITED(status) && WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 8)
            my_putstr("Floating exception");
        else
            my_putstr(strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status))
            my_putstr(CORE_DUMP);
        my_putstr("\n");
    }
}

void execve_error(char **av)
{
    if (errno == ENOEXEC) {
        my_putstr(av[0]);
        my_putstr(BAD_FORMAT);
    }
    else if (errno == EACCES) {
        my_putstr(av[0]);
        my_putstr(BAD_PERMISSION);
    }
}

int minishell1(char **av, char **env)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid != 0) {
        wait(&status);
        process_error(status);
    }
    else {
        if (execve(av[0], av, env) == -1)
            execve_error(av);
        exit(0);
    }
    return 0;
}