#include "shell.h"

/**
 * split_line - splits a line into tokens
 * @line: the input line
 *
 * Return: array of strings
 */
char **split_line(char *line)
{
	int i = 0;
	char **tokens = malloc(64 * sizeof(char *));
	char *token;

	if (!tokens)
		return (NULL);
	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * execute - forks and executes a command
 * @args: array of arguments
 *
 * Return: 1
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror("hsh");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
	return (1);
}

/**
 * get_location - Looks for a command in the directories listed in PATH
 * @command: The command to look for
 *
 * Return: Full path of the command if found, or NULL if not found
 */
char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	if (stat(command, &buffer) == 0)
	{
		return (strdup(command));
	}

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
	}

	return (NULL);
}
