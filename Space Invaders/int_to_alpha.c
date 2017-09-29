#include <stdio.h>
#include <stdlib.h>
#include "int_to_alpha.h"

char* int_to_alpha(int num)
{
		int div = 1;

		while(num / div > 9 || num / div < -9)
				div *=10;

		char* str = malloc(div*sizeof(char));

		int i = 0;

		if(num < 0)
		{
				str[0] = '-';
				num *= -1;
				i++;
		}

		while(div >= 1)
		{
				if(num > 0)
						str[i] = '0' + (num / div)%10;
				else
						str[i] = '0' - (num / div)%10;
				div = div / 10;
				i++;
		}

		return str;
}
