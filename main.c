# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <fcntl.h>

#include "libfts.h"

# define	MIN				( -4200 )
# define	MAX				( 5000 )
# define	STR_MAX_SIZE	( 10000 )
# define	random(min, max)( ( rand() % ( max - min ) ) + min )

static size_t	random_str( char *buff )
{
	size_t	len = random( 1, STR_MAX_SIZE );

	int i;
	for ( i = 0; i < len; ++i )
		buff[i] = random( 1, 256 );
	buff[i] = 0;
	return ( len );
}

void printmem(char *mem, int size)
{
	int i = 0;
	while(i < size)
		printf("[%c]", mem[i++]);
	printf("\n");
}

void check_puts(char *s)
{
	puts(s);
	ft_puts(s);
}
void check_isDigit(int i)
{
	printf("data: %c isdigit: %d, ft_isdigit: %d \n", i, isdigit(i), ft_isdigit(i));
}
void check_isAlpha(int i)
{
	printf("data: %c isalpha: %d, ft_isalpha: %d \n", i, isalpha(i), ft_isalpha(i));
}
void check_isAlnum(int i)
{
	printf("data: %c isalnum: %d, ft_isalnum: %d \n", i, isalnum(i), ft_isalnum(i));
}
void check_isAscii(int i)
{
	printf("data: %c isascii: %d, ft_isascii: %d \n", i, isascii(i), ft_isascii(i));
}
void check_isprint(int i)
{
	printf("data: %c isprint: %d, ft_isprint: %d \n", i, isprint(i), ft_isprint(i));
}
void check_tolower(int i)
{
	printf("data: %c tolower: %d, ft_tolower: %d \n", i, tolower(i), ft_tolower(i));
}
void check_toupper(int i)
{
	printf("data: %c toupper: %d, ft_toupper: %d \n", i, toupper(i), ft_toupper(i));
}
void check_strlen()
{
	int i = 0;
	printf( "--------\nTest ft_strlen:\n" );
	char	str[STR_MAX_SIZE];
	size_t	len;
	size_t	ft_len;

	for ( i = MIN; i < MAX; i++ )
	{
		len = random_str( str );
		if ( ( ft_len = ft_strlen( str ) ) != len )
		{
			printf("[%s] -> result: %d, expected result: %d\n", str, ft_len, len );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");
}



int main()
{
	puts("### ft_puts ##");
	check_puts("great succes !");
	check_puts(0);

	puts("### ft_isdigit ##");
	check_isDigit('5');
	check_isDigit('p');
	check_isDigit('0');
	check_isDigit('9');

	puts("### ft_alpha ##");
	check_isAlpha('A');
	check_isAlpha('Z');
	check_isAlpha('F');
	check_isAlpha('{');
	check_isAlpha(']');
	check_isAlpha('a');
	check_isAlpha('f');
	check_isAlpha('z');
	check_isAlpha('*');

	puts("### ft_alnum ##");
	check_isAlnum('5');
	check_isAlnum('p');
	check_isAlnum('0');
	check_isAlnum('9');
	check_isAlnum('A');
	check_isAlnum('Z');
	check_isAlnum('F');
	check_isAlnum('{');
	check_isAlnum(']');
	check_isAlnum('a');
	check_isAlnum('f');
	check_isAlnum('z');
	check_isAlnum('*');
	puts("### ft_alascii ##");
	check_isAscii('5');
	check_isAscii('p');
	check_isAscii('0');
	check_isAscii(150);
	check_isAscii(-4);
	check_isAscii(127);
	check_isAscii(0);
	check_isAscii('{');
	check_isAscii(']');
	check_isAscii('a');
	check_isAscii('f');
	check_isAscii('z');
	check_isAscii('*');
	puts("### ft_isprint ##");
	check_isprint('5');
	check_isprint('p');
	check_isprint('0');
	check_isprint(150);
	check_isprint(-4);
	check_isprint(127);
	check_isprint(0);
	check_isprint(32);
	check_isprint(126);
	check_isprint('{');
	check_isprint(']');
	check_isprint('a');
	check_isprint('f');
	check_isprint('z');
	check_isprint('*');
	puts("### ft_tolower ##");
	check_tolower('9');
	check_tolower('A');
	check_tolower('Z');
	check_tolower('F');
	check_tolower('{');
	check_tolower(']');
	check_tolower('a');
	check_tolower('z');
	puts("### ft_toupper ##");
	check_toupper('9');
	check_toupper('A');
	check_toupper('Z');
	check_toupper('F');
	check_toupper('{');
	check_toupper(']');
	check_toupper('a');
	check_toupper('z');
	int i = 0;
	srand( 42 );


	printf( "--------\nTest ft_bzero:\n" );
	char	str_bezro[STR_MAX_SIZE];
	char	str_ft_bezro[STR_MAX_SIZE];
	size_t	len_bzero;

	for ( i = MIN; i < MAX; i++ )
	{
		len_bzero = random_str( str_bezro );
		len_bzero -= random( 0, len_bzero );
		strcpy( str_ft_bezro, str_bezro );

		ft_bzero( str_ft_bezro, len_bzero );
		bzero( str_bezro, len_bzero );
		if ( memcmp( str_ft_bezro, str_bezro, len_bzero ) != 0 )
		{
			printf("result: \n%s\nexpected result: \n%s\n", str_ft_bezro, str_bezro );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");

	printf( "--------\nTest ft_strcat:\n" );
	char	str_strcat[STR_MAX_SIZE * 2];
	char	str_ft_strcat[STR_MAX_SIZE * 2];
	char	str_strcat_s2[STR_MAX_SIZE];
	char	*ret_strcat;
	char	*ret_ft_strcat;
	size_t	len_strcat;
	size_t	len_strcat_s2;

	for ( i = MIN; i < MAX; i++ )
	{
		len_strcat_s2 = random_str( str_strcat_s2 );
		len_strcat = random_str( str_strcat );
		strcpy( str_ft_strcat, str_strcat );

		ret_ft_strcat = ft_strcat( str_ft_strcat, str_strcat_s2 );
		ret_strcat = strcat( str_strcat, str_strcat_s2 );
		if ( memcmp( str_strcat, str_ft_strcat, len_strcat + len_strcat_s2 ) != 0 )
		{
			printmem( str_strcat, len_strcat );
			printmem( str_ft_strcat, len_strcat );
			printf("result: \n%s\nexpected result: \n%s\n", str_strcat, str_ft_strcat );
			exit( 0 );
		}
		if ( memcmp( ret_strcat, ret_ft_strcat, len_strcat + len_strcat_s2 ) != 0 )
		{
			printmem( ret_strcat, len_strcat );
			printmem( ret_ft_strcat, len_strcat );
			printf("result: \n%s\nexpected result: \n%s\n", ret_strcat, ret_ft_strcat );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");

	check_strlen();

	printf( "--------\nTest ft_memset:\n" );
	char	str_memset[STR_MAX_SIZE];
	char	str_ft_memset[STR_MAX_SIZE];
	size_t	len_memset;

	for ( i = MIN; i < MAX; i++ )
	{
		len_memset = random_str( str_memset );
		len_memset -= random( 0, len_memset );
		strcpy( str_ft_memset, str_memset );

		ft_memset( str_ft_memset, i, len_memset );
		memset( str_memset, i, len_memset );
		if ( memcmp( str_ft_memset, str_memset, len_bzero ) != 0 )
		{
			printf("result: \n%s\nexpected result: \n%s\n", str_ft_memset, str_memset );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");

	printf( "--------\nTest ft_memcpy:\n" );
	char	str_memcpy[STR_MAX_SIZE];
	char	str_ft_memcpy[STR_MAX_SIZE];
	char	str_memcpy_s2[STR_MAX_SIZE];
	size_t	len_memcpy;
	void	*ret_memcpy;
	void	*ret_ft_memcpy;

	for ( i = MIN; i < MAX; i++ )
	{
		len_memcpy = random_str( str_memcpy_s2 );

		ret_ft_memcpy = ft_memcpy( str_ft_memcpy, str_memcpy_s2, len_memcpy );
		ret_memcpy = memcpy( str_memcpy, str_memcpy_s2, len_memcpy );
		if ( memcmp( str_ft_memcpy, str_memcpy, len_memcpy ) != 0 )
		{
			printf("result: \n%s\nexpected result: \n%s\n", str_ft_memcpy, str_memcpy );
			exit( 0 );
		}
		if ( ret_ft_memcpy != str_ft_memcpy )
		{
			printf("result: \n%d\nexpected result: \n%d\n", (size_t)ret_ft_memcpy, (size_t)str_ft_memcpy );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");

	printf( "--------\nTest ft_strdup:\n" );
	char	str_strdup[STR_MAX_SIZE];
	size_t	len_strdup;
	char	*ret_ft_strdup;
	char	*ret_strdup;


	for ( i = MIN; i < MAX; i++ )
	{
		len_strdup = random_str( str_strdup );

		ret_ft_strdup = ft_strdup( str_strdup );
		ret_strdup = strdup( str_strdup );
		if ( memcmp( ret_ft_strdup, ret_strdup, len_strdup ) != 0 )
		{
			printf("result: \n%s\nexpected result: \n%s\n", ret_ft_strdup, ret_strdup );
			exit( 0 );
		}
	}
	printf("\033[32mOk\n\033[0m");
	printf( "--------\nTest ft_cat:\n" );
	ft_cat( 4 );
	ft_cat( 8 );
	ft_cat( -4 );
	// ft_cat( 0 );
	ft_cat( open( "ft_bzero.s", O_RDONLY ) );
	ft_cat( open( "libftasm.com", O_RDONLY ) );
	ft_cat( open( "/etc/shadow", O_RDONLY ) );
	return 0;
}
