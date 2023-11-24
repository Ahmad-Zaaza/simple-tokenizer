
#ifndef TOKEN_H
# define TOKEN_H

# include <stdbool.h>

typedef char		*t_char_itr;

typedef enum s_token_type
{
	DIGIT = 1,
	LOL = 2,
}					t_token_type;

typedef struct s_slice
{
	char			*start;
	int				length;
}					t_slice;

typedef struct s_token
{
	t_token_type	type;
	t_slice			location;
}					t_token;

char				peek(t_char_itr itr);
char				next(t_char_itr *itr);
bool				has_next(t_char_itr itr);

#endif