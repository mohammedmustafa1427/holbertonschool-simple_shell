#include "shell.h"

/**
 * main - Entry point for simple shell
 *
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char **args;
	char *full_path;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "($) ", 4);

		if (getline(&line, &len, stdin) == -1)
			break;

		args = split_line(line);

		if (args[0] != NULL)
		{
			full_path = get_location(args[0]);

			if (full_path != NULL)
			{
				args[0] = full_path;
				execute(args);
				free(full_path);
			}
			else
			{
				perror("hsh");
			}
		}
		free(args);
	}
	free(line);
	return (0);
}
