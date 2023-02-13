# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 11:39:24 by hznagui           #+#    #+#              #
#    Updated: 2023/02/06 13:17:44 by hznagui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME1 = mandatory/client

NAME2 = mandatory/server

NAME_B1 = bonus/client_bonus

NAME_B2 = bonus/server_bonus

ARC = libft/libft.a

all: $(NAME1) $(NAME2) 

$(NAME2): $(ARC) mandatory/server.c mandatory/minitalk.h
	cc -Wall -Wextra -Werror mandatory/server.c $< -o $@

$(NAME1): $(ARC) mandatory/client.c mandatory/minitalk.h
	cc -Wall -Wextra -Werror mandatory/client.c $< -o $@

$(NAME_B2): $(ARC) bonus/server_bonus.c	bonus/utils.c bonus/minitalk_bonus.h
	cc -Wall -Wextra -Werror bonus/server_bonus.c bonus/utils.c $< -o $@

$(NAME_B1): $(ARC) bonus/client_bonus.c bonus/minitalk_bonus.h
	cc -Wall -Wextra -Werror bonus/client_bonus.c  $< -o $@

$(ARC): libft/*.c
	make -C libft

clean: 
	make clean -C libft

fclean:
	rm -f $(NAME1) $(NAME2) $(NAME_B1) $(NAME_B2)
	make fclean -C libft
	
re: fclean all

bonus: $(NAME_B1) $(NAME_B2) 