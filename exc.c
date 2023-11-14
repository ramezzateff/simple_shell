#include "main.h"

/**
 * _exc - Executes a command.
 * @argv: An array containing the command and its arguments.
 */
void _exc(char *argv[])
{
	char full_path[MAX_COMMAND_LENGTH];

	if (!search_command(argv[0], full_path))
	{
		printf("Command not found: %s\n", argv[0]);
		return;
	}

	pid_t Pid, Wpid;
	int status;

	Pid = fork();

	if (Pid == 0)
	{
		if (execve(full_path, argv, NULL) == -1)
		{
			perror("shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (Pid < 0)
	{
		perror("shell");
	}
	else
	{
		do {
			Wpid = waitpid(Pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}

