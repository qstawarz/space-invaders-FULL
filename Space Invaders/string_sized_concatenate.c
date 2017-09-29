#include <stdio.h>
#include <stdlib.h>
#include "string_length.h"
#include "string_sized_copy.h"
#include "string_sized_concatenate.h"

char* string_sized_concatenate(char* dest, char const* src, unsigned int size_max)
{
		if(dest == NULL)
				return NULL;

		if(src == NULL || size_max == 0)
				return dest;

		unsigned int n = string_length(dest);

		string_sized_copy(&dest[n], src, size_max);

		return dest;
}
