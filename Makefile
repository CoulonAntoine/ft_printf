# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 11:41:35 by ancoulon          #+#    #+#              #
#    Updated: 2020/02/10 16:13:20 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBDIR		= ./libft

LIB			= libft.a

INCDIR		= ./includes

SRCDIR		= ./sources

SRCS		= ft_printf.c ft_utils.c ft_parse.c ft_get_format.c

OBJS		= $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

CC			= gcc

AR			= ar rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			$(CC) $(CFLAGS) -I$(INCDIR) -c $^ -o $@

all:		$(NAME)

$(LIB):
			echo "test\n";
			make -C $(LIBDIR)
			make -C $(LIBDIR) clean


$(NAME):	$(OBJS)
			echo "test\n";
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)
			$(RM} $(OBJS_BONUS)

fclean:		clean
			$(RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
