#include "main.h"

/**
 * parse_command - Parses a command string into an array of arguments.
 * @command: The command string to be parsed.
 * @argv: An array to store the parsed arguments.
 *
 * Return: The number of arguments (argc).
 */
int parse_command(char *command, char *argv[])
{
	int argc = 0;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
	argv[argc++] = token;
	token = strtok(NULL, " ");
	}

	argv[argc] = NULL;

	return (argc);
}

/**
 * search_command - Searches for a command in the directories
 specified by the PATH environment variable.
 * @command: The command to search for.
 * @full_path: The buffer to store the full path of the command.
 *
 * Return: 1 if the command is found, 0 otherwise.
 */
int search_command(char *command, char *full_path)
{
	char *path_env = getenv("PATH");
	char *path = strtok(path_env, ":");

	while (path != NULL)
	{
	sprintf(full_path, "%s/%s", path, command);
	if (access(full_path, F_OK) != -1)
	{
	return (1);
	}

	path = strtok(NULL, ":");
	}

	return (0);
}
