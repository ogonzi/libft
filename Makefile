# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 10:31:35 by ogonzale          #+#    #+#              #
#    Updated: 2022/04/26 10:02:07 by ogonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
LIB2	= ranlib
RM	= /bin/rm -f

NAME	= libft.a

SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  		ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_toupper.c \
	 		ft_tolower.c ft_strchr.c ft_strrchr.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memmove.c \
			ft_strnstr.c ft_strdup.c ft_calloc.c ft_atoi.c
OBJS	= $(SRCS:.c=.o)
BONUS_S	= ft_islower_bonus.c ft_isupper_bonus.c ft_isspace_bonus.c ft_pow_bonus.c
BONUS_O	= $(BONUS_S:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
		$(LIB1) $(NAME) $(OBJS)
		$(LIB2) $(NAME)

bonus:		$(NAME) $(BONUS_O)
		$(LIB1) $(NAME) $(BONUS_O)
		$(LIB2) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
