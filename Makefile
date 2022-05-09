# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogonzale <ogonzale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 10:31:35 by ogonzale          #+#    #+#              #
#    Updated: 2022/05/09 17:28:37 by ogonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
LIB2	= ranlib
RM	= /bin/rm -f
HEADER = libft.h
NAME	= libft.a

SRCS	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  		ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_toupper.c \
	 		ft_tolower.c ft_strchr.c ft_strrchr.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c \
			ft_strnstr.c ft_strdup.c ft_calloc.c ft_atoi.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_lstnew.c ft_lstadd_front.c \
			ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_itoa.c ft_strmapi.c \
			ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c
OBJS	= $(SRCS:.c=.o)
BONUS_S	= ft_islower_bonus.c ft_isupper_bonus.c ft_isspace_bonus.c ft_pow_bonus.c \
		  ft_is_in_set_bonus.c ft_numsize_bonus.c ft_abs_value_bonus.c \
		  ft_memccpy_bonus.c
BONUS_O	= $(BONUS_S:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(INCLUDE) $(HEADER)
		$(LIB1) $(NAME) $(OBJS)
		$(LIB2) $(NAME)

bonus:		$(NAME) $(BONUS_O) $(HEADER)
		$(LIB1) $(NAME) $(BONUS_O)
		$(LIB2) $(NAME)
		@touch $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS) $(BONUS_O)

fclean:		clean
		$(RM) $(NAME)
		$(RM) bonus

re:		fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re rebonus
