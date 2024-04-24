SRCS = main.c count_string.c fill_array.c fill_tab.c free_stack.c ft_free.c input_check.c \
		lst_new.c node_size.c sorted_four_five.c sorted_three.c  ft_atol.c \
		ft_swap.c instructions.c sorted_stack.c sorted_two.c searching.c 

OBJS = $(SRCS:.c=.o)

NAME 		= push_swap
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
RM 			= rm -f

LIBFT 		= libft/libft.a

all: 		$(NAME)

$(NAME): 	$(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
			@$(MAKE) -C libft

clean:
			$(RM) $(OBJS)
			$(MAKE) -C libft clean

fclean: 	clean
			$(RM) $(NAME)
			$(MAKE) -C libft fclean

re: 		fclean $(NAME)

.PHONY: 	all clean fclean re

