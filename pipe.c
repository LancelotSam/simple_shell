#include "shell.h"
/**
 * my-pipe-this is the main function
 * it accomodates for piping functions
 * @args:an array of arguments
 * Return: int status
 */
int my_pipe(char *args[])
{
	int pipefd[2], i, j;
	pid_t child1, child2;
	char **firstCommandArgs = NULL;
	char **secondCommandArgs = NULL;
	int isPipePresent = 0, secondCommandArgCount;

	if (pipe(pipefd) == -1)
	{
		perror("Pipe creation failed");
		exit(EXIT_FAILURE);
	}
	for (i = 0; args[i] != NULL; i++)
	{
		if (strcmp(args[i], "|") == 0)
		{
			isPipePresent = 1;
			args[i] = NULL;
			break;
		}
	}
	firstCommandArgs = malloc((i + 1) * sizeof(char *));
	if (firstCommandArgs == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	for (j = 0; j < i; j++)
	{
		firstCommandArgs[j] = args[j];
	}
	firstCommandArgs[i] = NULL;
	if (isPipePresent)
	{
		secondCommandArgCount = 0;
		for (; args[i + secondCommandArgCount + 1] != NULL; secondCommandArgCount++)
		{
		}
		secondCommandArgs = malloc((secondCommandArgCount + 1) * sizeof(char *));
		if (secondCommandArgs == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		for (j = 0; j < secondCommandArgCount; j++)
		{
			secondCommandArgs[j] = args[i + j + 1];
		}
		secondCommandArgs[secondCommandArgCount] = NULL;
	}
	child1 = fork();
	if (child1 < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (child1 == 0)
	{
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		{
			perror("Duplication of file descriptor failed");
			exit(EXIT_FAILURE);
		}
		close(pipefd[0]);
		execute_Command(firstCommandArgs);
	}
	child2 = fork();
	if (child2 < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (child2 == 0)
	{
		dup2(STDOUT_FILENO, pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
		{
			perror("Duplication of file descriptor failed");
			exit(EXIT_FAILURE);
		}
		close(pipefd[1]);
		if (isPipePresent)
		{
			execute_Command(secondCommandArgs);
		} else
		{
			fprintf(stderr, "No second command provided\n");
			exit(EXIT_FAILURE);
		}
	} else if (child2 > 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		waitpid(child1, NULL, 0);
		waitpid(child2, NULL, 0);
		free(firstCommandArgs);
		free(secondCommandArgs);
	}
	return (-1);
}
