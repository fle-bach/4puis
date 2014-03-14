# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/26 09:33:53 by fle-bach          #+#    #+#              #
#    Updated: 2014/03/05 16:59:19 by fle-bach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sh_42

SRCS = main.c ft_sh.c ft_path_prompt_exe.c ft_other_commande.c ft_error.c \
	   ft_init_free_sh.c ft_envp.c ft_unsetenv.c ft_setenv.c ft_cd.c \
	   ft_error_cd.c ft_dup.c ft_pipe.c

HEADER = -I./libft/includes

LIB = libft/libft.a

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror


.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAG) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c
	gcc $(FLAG) -c $(HEADER) $< -o $@

clean:
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
