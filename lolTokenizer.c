#include "./includes/Token.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

char	peak(t_char_itr itr)
{
	return (*itr);
}

char	next(t_char_itr *itr)
{
	char	next;

	next = **itr;
	(*itr)++;
	return (next);
}

bool	has_next(t_char_itr itr)
{
	return (*itr != '\0' && *itr != '\n');
}

t_token	take_digit(t_char_itr *itr)
{
	t_slice	location;
	t_token	token;

	location.start = *itr;
	location.length = 1;
	next(itr);
	token.type = DIGIT;
	token.location = location;
	return (token);
}

t_token	take_lol(t_char_itr *itr)
{
	t_slice	location;
	t_token	token;
	char	c;
	int		length;

	length = 1;
	location.start = *itr;
	location.length = 0;
	next(itr);
	c = peak(*itr);
	if (c == 'o')
	{
		next(itr);
		length++;
	}
	c = peak(*itr);
	if (c == 'l')
	{
		next(itr);
		length++;
	}
	c = peak(*itr);
	while (c == 'l' || c == 'o')
	{
		next(itr);
		c = peak(*itr);
		length++;
	}
	location.length = length;
	token.type = LOL;
	token.location = location;
	return (token);
}

static void	print_token(t_token token)
{
	int	i;

	i = 0;
	printf("TOKEN [Type]: %d => (", token.type);
	while (i < token.location.length)
	{
		printf("%c", token.location.start[i]);
		i++;
	}
	printf(")\n");
}

static void	process_buffer(t_char_itr *buffer)
{
	char		c;
	t_token		token;
	t_char_itr	iter;

	iter = *buffer;
	while (has_next(iter))
	{
		c = peak(iter);
		if (isdigit(c))
			token = take_digit(&iter);
		else if (c == 'l')
			token = take_lol(&iter);
		else
		{
			token.location.start = NULL;
			token.type = 0;
			token.location.length = 0;
			return ;
		}
		print_token(token);
	}
}
int	main(void)
{
	t_char_itr	buffer;

	while ((buffer = readline("LOLTokenizer > ")))
	{
		process_buffer(&buffer);
	}
	return (0);
}
