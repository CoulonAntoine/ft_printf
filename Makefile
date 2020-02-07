# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 11:41:35 by ancoulon          #+#    #+#              #
#    Updated: 2020/02/07 15:05:25 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

HEADER		= ft_printf.h

LIBDIR		= ./libft

LIB			= libft.a

SRCS		= ft_printf.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

AR			= ar rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $^ -o $@

$(LIB):
			make -C ${LIBDIR}
			make -C ${LIBDIR} clean

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}
			${RM} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re norm libft
