#include "main.h"

/**
 * _getline - Reads a line from the standard input.
 * @command: Pointer to the buffer where the line is stored.
 *
 * Return: Always 0.
 */
size_t _getline(char *command)
{
	size_t len = 0;

	while (1)
	{
	printf("$ ");
	fflush(stdout);

	ssize_t read = getline(&command, &len, stdin);

	if (read == -1)
	{
	printf("\n");
	exit(0);
	}

	command[strcspn(command, "\n")] = '\0';
	char *argv[MAX_COMMAND_LENGTH];
	int argc = parse_command(command, argv);

	if (argc > 0)
	{
	_exc(argv);
	}
	}
	return (0);
}
