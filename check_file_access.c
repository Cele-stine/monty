#include "monty.h"

/**
 * check_File_access - a function that checks the access permissition of a file
 * @path: the file path to the file
 * @amed: the permmissions to the file
 * Return: 0 on success otherwise -1
 */

int check_File_access(const char *path, int amed)
{
	if (access(path, amed) == 0)
	{
		return (0);
	}
	else
		return (-1);
}
