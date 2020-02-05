# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 11:41:35 by ancoulon          #+#    #+#              #
#    Updated: 2020/02/04 23:35:47 by ancoulon         ###   ########.fr        #
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

norm:		
			${NORM} ${HEADER} ${SRCS}

.PHONY:		all clean fclean re norm libft
