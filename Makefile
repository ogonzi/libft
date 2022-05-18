# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogonzale <ogonzale@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 10:00:13 by ogonzale          #+#    #+#              #
#    Updated: 2022/05/18 11:14:03 by ogonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard

NAME = libft.a
INCLUDES = include/
SRC_DIR = src/
OBJ_DIR = obj/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
RM = /bin/rm -f
AR = ar -rcs

#Sources

FTIS_DIR = ft_is/
FTIS = ft_is_in_set ft_isalpha ft_isdigit ft_isprint ft_isupper ft_isalnum \
	   ft_isascii ft_islower ft_isspace

FTMEM_DIR = ft_mem/
FTMEM = ft_bzero ft_memccpy ft_memcmp ft_memmove ft_realloc ft_calloc \
		ft_memchr ft_memcpy ft_memset

FTPUT_DIR = ft_put/
FTPUT = ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd

FTTO_DIR = ft_to/
FTTO = ft_atoi ft_atoi_base ft_itoa ft_tolower ft_toupper

FTSTR_DIR = ft_str/
FTSTR = ft_split ft_strcat ft_strchr ft_strdup ft_striteri ft_strjoin \
		ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr \
		ft_strrchr ft_strtrim ft_substr

FTMATH_DIR = ft_math/
FTMATH = ft_abs_value ft_numsize ft_pow

FTLST_DIR = ft_lst/
FTLST = ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter \
		ft_lstlast ft_lstmap ft_lstnew ft_lstsize

SRC_FILES+=$(addprefix $(FTIS_DIR), $(FTIS))
SRC_FILES+=$(addprefix $(FTMEM_DIR), $(FTMEM))
SRC_FILES+=$(addprefix $(FTPUT_DIR), $(FTPUT))
SRC_FILES+=$(addprefix $(FTTO_DIR), $(FTTO))
SRC_FILES+=$(addprefix $(FTSTR_DIR), $(FTSTR))
SRC_FILES+=$(addprefix $(FTMATH_DIR), $(FTMATH))
BONUS_FILES+=$(addprefix $(FTLST_DIR), $(FTLST))

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
BONUS_OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUS_FILES)))

###

OBJF = .cache_exists

all:	$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(FTIS_DIR)
	mkdir -p $(OBJ_DIR)$(FTMEM_DIR)
	mkdir -p $(OBJ_DIR)$(FTPUT_DIR)
	mkdir -p $(OBJ_DIR)$(FTTO_DIR)
	mkdir -p $(OBJ_DIR)$(FTSTR_DIR)
	mkdir -p $(OBJ_DIR)$(FTMATH_DIR)
	mkdir -p $(OBJ_DIR)$(FTLST_DIR)

bonus:	$(BONUS_OBJ)
	$(AR) $(NAME) $(BONUS_OBJ)

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(OBJF)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

norm:
	@norminette $(SRC) $(INCLUDES) | grep -v Norme -B1 || true

.PHONY:	all clean fclean re norm
