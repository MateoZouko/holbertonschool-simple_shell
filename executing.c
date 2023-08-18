#include "main.h"

/**
 * executing - executes a program in a child process
 * @path: point to the path thay contains the operation
 * @array: tokenized array
 * Return: 1/0
 */

int executing(char *path, char **array, char **environment)
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
		execve(path, array, environment);
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
