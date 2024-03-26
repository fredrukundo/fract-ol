# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 19:52:25 by frukundo          #+#    #+#              #
#    Updated: 2024/03/26 19:52:26 by frukundo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRS_F = fractol.c building.c control_way.c fractol_utile.c  window_construction.c

FLAGS = -Wall -Wextra -Werror
NAME = fractol
HEADER = fractol.h
OBG_F = $(SRS_F:.c=.o)

all : $(NAME)

$(NAME) : $(OBG_F)
	cc -lmlx -framework OpenGL -framework AppKit $^ -o $(NAME)

%.o : %.c $(HEADER)
	cc $(FLAGS) -c $<

clean : 
	rm -f $(OBG_F)

fclean : clean
	rm -rf $(NAME)

re : fclean all