#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf(" indicateur . : %.1s", "salut les amis") ;
	printf(" indicateur . : %.10s", "salut les amis");
	printf(" indicateur . : %.3s", "salut les amis" ) ;
    /*ft_printf("%d\n", 42);
	printf("%d\n", 42);
	ft_printf("%s\n", "hello world");
	printf("%s\n", "hello world");
	ft_printf("%i\n", 42);
	printf("%i\n", 42);
	ft_printf("%u\n", -42);
	printf("%u\n", -42);
	ft_printf("%x et %X\n", 42, 42);
	printf("%x et %X\n", 42, 42);
	ft_printf("%c\n", '4');
	printf("%c\n", '4');*/
    return 0;
}
