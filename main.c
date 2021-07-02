#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char str[] = "hello world";

	printf("avec d %d salut42\n", 42); 
	ft_printf("avec d %d salut42\n", 42);

	printf("avec u %u salut42 \n", -4200000);
	ft_printf("avec u %u salut42 \n", -4200000);

	printf("%X \n", 42);
	ft_printf("%X \n", 42);

	//printf("%12s , cool\n", str);
	//ft_printf("%12s , cool\n", str); // ce fdp imprime 50 space au lieu de 5 

	//printf("salut %% bien\n", ' ');
	//ft_printf("salut %% bien\n",' ');
}
