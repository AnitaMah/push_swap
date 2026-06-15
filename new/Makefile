# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmakhov <anmakhov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/12 11:26:53 by anmakhov          #+#    #+#              #
#    Updated: 2026/06/15 14:07:24 by anmakhov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

LIBFT = libft/libft.a

SRC = main/main.c \
	main/init_stack.c \
	main/parse_args.c \
	main/is_sorted.c \
	main/free_stack.c \
	main/compute_disorder.c \
	main/normalize_index.c \
	main/stack_from_array.c \
	\
	untils/untils_parsing.c \
	untils/ft_atoi_ps.c \
	\
	stack_operations/push.c \
	stack_operations/reverse.c \
	stack_operations/rotate.c \
	stack_operations/swap.c \
	\
	stack_sorting/chunk_sort.c \
	stack_sorting/bring_to_top.c \
	stack_sorting/restore_to_a.c \
	stack_sorting/radix_sort.c \
	stack_sorting/selections_sort_addaptation.c \
	stack_sorting/quick_sort.c \
	stack_sorting/sort_small.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
