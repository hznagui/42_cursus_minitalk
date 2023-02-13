# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hznagui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 20:32:32 by hznagui           #+#    #+#              #
#    Updated: 2022/11/02 20:32:39 by hznagui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
			ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
			ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
			ft_substr.c ft_tolower.c ft_toupper.c

BONUS_FILE 	=  ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c  ft_lstnew.c ft_lstiter.c ft_lstmap.c

NAME = libft.a

OBJ_FILE = $(SRC_FILE:.c=.o)

BONUS_OBJ = $(BONUS_FILE:.c=.o) 

$(NAME):	$(OBJ_FILE)
		ar -rc $(NAME) $(OBJ_FILE)

all: $(NAME)

%.o : %.c libft.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ_FILE) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(BONUS_OBJ) $(OBJ_FILE)
	ar -rc $(NAME) $(BONUS_OBJ) $(OBJ_FILE)
