#include "holberton.h"
/**
 * conthand - That handle the signal of ^C.
 * @handle_signal: The signal that enters..
 *
 * Return: Void Funtion.
 */
void conthand(int handle_signal)
{
	if (handle_signal)
		write(STDIN_FILENO, "\n#cisfun$ ", 10);
}
