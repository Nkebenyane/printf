# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnkebeny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/07 12:32:00 by mnkebeny          #+#    #+#              #
#    Updated: 2018/08/09 10:20:50 by mnkebeny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= libftprintf.a

CC				:= gcc
CFLAGS			+= -Wall -Wextra
CFLAGS			+= -Werror
CFLAGS			+= -I includes/

LIBFTPRINTF		:= -L. -lftprintf
	
SRC_FILES		:= ft_printf.c \
				ft_confirm.c \
				ft_solve.c \
				ft_optional.c \
				ft_sort_1.c \
				ft_sort_2.c \
				ft_printf_c.c \
				ft_printf_d.c \
				ft_printf_p.c \
				ft_printf_s.c \
				ft_printf_b.c \
				ft_printf_n.c \
				ft_printf_f.c \
				ft_printf_x.c \
				ft_printf_u.c \
				ft_printf_o.c \
				ft_wctomb.c \
				ft_nbrlen.c \
			  	ft_itoa_base.c \
			  	ft_nbrlen_base.c \
				

LIBFT_FILES		:= ft_putchar.c \
			  ft_putchar_fd.c \
			  ft_strcmp.c \
			  ft_putendl.c \
			  ft_putendl_fd.c \
			  ft_putnbr.c \
			  ft_putstr.c \
			  ft_putstr_fd.c \
			  ft_putnbr_fd.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_memcpy.c \
			  ft_memalloc.c \
			  ft_memdel.c \
			  ft_memccpy.c \
			  ft_memchr.c \
			  ft_memmove.c \
			  ft_bzero.c \
			  ft_memset.c \
			  ft_memcmp.c \
			  ft_strcat.c \
			  ft_strncat.c \
			  ft_strlcat.c \
			  ft_strncmp.c \
			  ft_strlen.c \
			  ft_strcpy.c \
			  ft_strclr.c \
			  ft_strncpy.c \
			  ft_strdup.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strstr.c \
			  ft_strnstr.c \
			  ft_strnew.c \
			  ft_strdel.c \
			  ft_striter.c \
			  ft_striteri.c \
			  ft_strsplit.c \
			  ft_strequ.c \
			  ft_strnequ.c \
			  ft_strsub.c \
			  ft_strmap.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_strmapi.c \
			  ft_atoi.c \
			  ft_itoa.c \
			  ft_lstnew.c \
			  ft_lstadd.c \
			  ft_lstiter.c \
			  ft_lstdel.c \
			  ft_lstdelone.c \
			  ft_lstmap.c \
			  

SRC			:= $(addprefix src/, $(SRC_FILES))
LIBFT			:= $(addprefix libft/, $(LIBFT_FILES))

OBJ			:= $(SRC:.c=.o)
OBJLIBFT 		:= $(LIBFT:.c=.o)
OBJTEST			:= $(TEST:.c=.o)

.PHONY = all clean fclean clean re

all: $(NAME)
	@make all -C ./libft

$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJLIBFT): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJLIBFT) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(OBJLIBFT)

clean:
	@rm -rf $(OBJ) $(OBJLIBFT) $(OBJTEST)

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)

re: fclean all

