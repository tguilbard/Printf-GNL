# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tguilbar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 12:48:05 by tguilbar          #+#    #+#              #
#    Updated: 2019/11/26 13:37:21 by tguilbar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CFLAGS	= -Wall -Wextra -Werror
FILES	=	ft_formatchar.c ft_formatstring.c ft_printf.c ft_utils.c z_z.c \
			ft_formatadr.c ft_formatint.c ft_formatunsint.c \
			ft_strlen.c

OBJ		= $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
