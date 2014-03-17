# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fle-bach <fle-bach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 17:51:17 by fle-bach          #+#    #+#              #
#    Updated: 2014/02/18 14:36:33 by fle-bach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -Wall -Wextra -Werror

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_isspace.c \
	ft_putnbr.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	get_next_line.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_swap_ptr.c \
	ft_sort_strs.c \
	ft_swap_lst.c \
	ft_sort_lst.c \
	ft_isblank.c \
	ft_strnjoin.c \
	ft_startswith.c \
	ft_indexof.c \
	ft_lstpush.c \
	ft_dabs.c \
	ft_fabs.c \
	ft_iabs.c \
	ft_labs.c \
	ft_powi.c \
	ft_putdouble.c \
	ft_putlong.c \
	ft_putfloat.c \
	ft_powl.c \
	ft_strsplit_trim.c \
	ft_strlen2.c \
	ft_realloc.c \
	ft_free_double_tab.c

OBJ = $(SRC:.c=.o)

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;35;m[Linking] \t\t\033[0m: " | tr -d '\n'
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\033[1;32;m[Success] \t\t\t\033[0m"

%.o: %.c
	@echo "\033[1;36;m[Compiling $<] \t\033[0m: " | tr -d '\n'
	$(CC) -c -I./includes $< -o $@

clean:
	@echo "\033[0;33;m[Cleaning] \t\t\033[0m: " | tr -d '\n'
	/bin/rm -rf $(OBJ)

fclean: clean
	@echo "\033[0;31;m[Deleting $(NAME)] \t\033[0m: " | tr -d '\n'
	/bin/rm -rf $(NAME)

re: fclean all
