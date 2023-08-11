#include "main.h"

int executing(char *path, char **string)
{
    int st, exit_st;
    pid_t pid;

    pid = fork();

    if (pid == -1)
    {
        return (1);
    }

    if (pid == 0)
    {
        execve(path, string, NULL);
        return (1);
    }

    else
    {
        if (wait(&st) == -1)
        {
            return (1);
        }
    }

    if (WIFEXITED(st))
    {
        exit_st = WEXITSTATUS(st);
        if (exit_st == 0)
            return (0);
        else
            return (1);
    }

    if (WIFSIGNALED(st))
        return (1);

    return (1);
}