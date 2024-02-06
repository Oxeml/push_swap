CC		= cc
CFLAGS	=
NAME	= push_swap
OBJDIR	= obj
SRCS	= $(wildcard *.c)
OBJS	= $(patsubst %.c,$(OBJDIR)/%.o,$(SRCS))
HEADERS	= push_swap.h

ifndef LENIENT
	CFLAGS += -Wall -Werror -Wextra
endif

ifdef DEBUG
	CFLAGS += -g
endif

all: $(NAME)

$(OBJDIR)/%.o: %.c $(HEADERS) Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re
