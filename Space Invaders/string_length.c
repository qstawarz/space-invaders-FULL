#include <stdio.h>
#include "string_length.h"
#include <stdlib.h>

unsigned int string_length(char const* str)
{
    int n = 0;
    
    if(str == NULL)
        return n;
    do
    {
        n++;
    }
    while(str[n] != '\0');

    return n;
}
