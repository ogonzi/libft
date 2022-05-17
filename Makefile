# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 11:20:27 by ogonzale          #+#    #+#              #
#    Updated: 2022/05/17 15:13:10 by ogonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
RM	= /bin/rm -f
HEADER = libft.h
NAME	= libft.a

SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  		ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_toupper.c \
	 		ft_tolower.c ft_strchr.c ft_strrchr.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c \
			ft_strnstr.c ft_strdup.c ft_calloc.c ft_atoi.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
			ft_striteri.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c

OBJS	= $(SRCS:.c=.o)

BONUS_S	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BONUS_O	= $(BONUS_S:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(INCLUDE) $(HEADER)
		$(LIB1) $(NAME) $(OBJS)

bonus:		$(NAME) $(BONUS_O) $(HEADER)
		$(LIB1) $(NAME) $(BONUS_O)
		@touch $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
		$(RM) $(NAME)
		$(RM) bonus

re:		fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re rebonus
