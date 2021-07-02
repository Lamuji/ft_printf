#include <stdio.h>
#include "ft_printf.h"

int main()
{
	// char str[] = "hello";
	// int i = 42;

	//printf("minus %-8dsalut42\n", 4255); 
	//ft_printf("minus %-8dsalut42\n", 4255);

	//printf("%-22u sd\n", -42);
	//ft_printf("%-22u sd\n", -42);

	printf("haha %-22X haha\n", 42);
	ft_printf("haha %-22X haha\n", 42);

	// printf("%-140c ,cool\n", 'a');
	// ft_printf("%-140c ,cool\n", 'a'); // ce fdp imprime 50 space au lieu de 5 

	//printf("salut %% bien\n", ' ');
	//ft_printf("salut %% bien\n",' ');

// 	printf("%p\n", &str);
// 	printf("%p\n", &i);
// 	ft_printf("%X", &i);
 }
