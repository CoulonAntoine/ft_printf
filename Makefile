# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 11:41:35 by ancoulon          #+#    #+#              #
#    Updated: 2020/02/11 08:30:13 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBDIR		= ./libft

LIB			= libft.a

INCDIR		= ./includes

SRCDIR		= ./sources

SRCS		= 

OBJS		= $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rc

RM			= rm -f

MAKE		= make

.c.o:
			$(CC) $(CFLAGS) -I$(INCDIR) -c $^ -o $@

all:		$(NAME)

$(NAME):	$(LIB) $(OBJS)
			$(AR) $(NAME) $(LIBDIR)/$(LIB) $(OBJS)

$(LIB):
			$(MAKE) -C $(LIBDIR)

clean:
			$(MAKE) -C $(LIBDIR) clean
			$(RM) $(OBJS)
			$(RM) $(OBJS_BONUS)

fclean:		clean
			$(MAKE) -C $(LIBDIR) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
