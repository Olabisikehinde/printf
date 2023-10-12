#include <stdlib.h>
#include "function_pointers.h"

/**
 * print_name - to prints a name
 * @name: the name to print
 * @f: the pointer to the printing function
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;
	f(name);
}
