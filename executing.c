#include "main.h"

int executing(char *path, char **string)
{
    pid_t pid;
    int stats, exit_;

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
        if (wait(&stats) == -1)
        {
            return (1);
        }
    }

    if (WIFEXITED(stats))
    {
        exit_ = WEXITSTATUS(stats);
        if (exit_ == 0)
            return (0);
        else
            return (1);
    }

    if (WIFSIGNALED(stats))
        return (1);

    return (1);
}
