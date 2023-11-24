NAME = lolTokenizer
DEBUG = lolTokenizerDebug
cc = gcc
CFLAGS = -Wall -Wextra -Werror

DEBUG_FLAGS = -g3 -fsanitize=address

LIBS_FLAGS = -lreadline

all :$(NAME)
debug: $(DEBUG)

SRCS = lolTokenizer.c
OBJS = $(SRCS:%.c=%.o)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBS_FLAGS)  $^ -o $@

$(DEBUG): $(OBJS)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(LIBS_FLAGS)  $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(DEBUG)

re: fclean all
.PHONY: all clean fclean re