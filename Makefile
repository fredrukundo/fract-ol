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