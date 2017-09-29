#include <stdio.h>
#include <stdlib.h>
#include "string_sized_concatenate.h"
#include "string_safe_concatenate.h"

char* string_safe_concatenate(char* dest, const char* src, unsigned int size_max)
{
		if(dest == NULL)
				return dest;

		if(src == NULL || size_max == 0)
				return dest;

		char* c = string_sized_concatenate(dest, src, size_max);

		c[size_max-1] = '\0';

		return c;
}
