# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 11:39:24 by hznagui           #+#    #+#              #
#    Updated: 2023/01/30 16:35:42 by hznagui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILE = client.c server.c

# NAME = push_swap.a

# PROGRAM = push_swap

OBJ_FILE = $(SRC_FILE:.c=.o)

# $(PROGRAM):  $(NAME)
# 	cc -Wall -Wextra -Werror $< -o $@

all: $(PROGRAM)


# $(NAME): $(OBJ_FILE)
# 	ar -rc $(NAME) $(OBJ_FILE)

%.o : %.c minitalk.h
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ_FILE)
	
fclean:	clean
	rm -f $(NAME) $(PROGRAM)
	
re: fclean all