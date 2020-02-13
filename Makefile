# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 11:41:35 by ancoulon          #+#    #+#              #
#    Updated: 2020/02/13 12:05:43 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBDIR		= ./libft

LIB			= libft.a

INCDIR		= ./includes

SRCDIR		= ./sources

SRCS		= ft_printf.c ft_process.c ft_parse.c ft_parse_utils.c

OBJS		= $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR			= libtool -static -o

RM			= rm -f

MAKE		= make

.c.o:
			$(CC) $(CFLAGS) -I$(INCDIR) -c $^ -o $@

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIBDIR)
			$(AR) $(NAME) $(LIBDIR)/$(LIB) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

clean:
			$(MAKE) -C $(LIBDIR) clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) -C $(LIBDIR) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
