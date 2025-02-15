# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lafontai <lafontai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/23 09:39:28 by lafontai          #+#    #+#              #
#    Updated: 2020/06/02 15:27:43 by lafontai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_strlen.s ft_strdup.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s

OBJS	= $(SRCS:.s=.o)

NAME	= libasm.a

RM		= rm -f

CC		= nasm

CFLAGS	= -f elf64

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o:		%.s
			$(CC) $(CFLAGS) $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

tclean:		fclean
			$(RM) a.out
			$(RM) tests

re:			fclean all

.PHONY:		all clean fclean re
