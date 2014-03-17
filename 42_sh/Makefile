# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/26 09:33:53 by fle-bach          #+#    #+#              #
#    Updated: 2014/03/17 11:34:34 by fle-bach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sh_42

SRCS = ft_path_prompt_exe.c \
	ft_other_commande.c \
	ft_init_free_sh.c \
	ft_unsetenv.c \
	ft_error_cd.c \
	ft_setenv.c \
	ft_error.c \
	ft_envp.c \
	ft_pipe.c \
	ft_dup.c \
	ft_cut.c \
	ft_sh.c \
	ft_cd.c \
	main.c

HEADER1 = -I./libft/includes

HEADER2 = -I./includes

LIB = libft/libft.a

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror


.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	@echo "\033[1;35;m[Linking] \t\t\033[0m: " | tr -d '\n'
	gcc $(FLAG) $(OBJ) $(LIB) -o $(NAME)
	@echo "\033[1;32;m[Success] \t\t\t\033[0m"

%.o: %.c
	@echo "\033[1;36;m[Compiling $<] \t\033[0m: " | tr -d '\n'
	gcc $(FLAG) -c $(HEADER1) $(HEADER2) $< -o $@

clean:
	make clean -C libft/
	@echo "\033[0;33;m[Cleaning] \t\t\033[0m: " | tr -d '\n'
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	@echo "\033[0;31;m[Deleting $(NAME)] \t\033[0m: " | tr -d '\n'
	rm -f $(NAME)

re: fclean all
