#include <stdio.h>
#include <stdlib.h>
#include "string_length.h"
#include "string_sized_copy.h"

char* string_sized_copy(char* dest, char const* src, unsigned int size_max)
{
		if(dest == NULL)
				return NULL;

		if(src == NULL || size_max == 0)
				return dest;

		unsigned int n = string_length(dest);
		unsigned int i = 0;

		while(i < size_max)
		{
				dest[i] = src[i];
				i++;
		}

		if(size_max > n)
				dest[i] = '\0';

		return dest;		
}
