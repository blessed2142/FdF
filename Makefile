SRCS	=	./src/draw.c ./src/draw_2.c ./src/draw_utils.c \
			./src/error.c ./src/key.c ./src/main.c \
			./src/params.c ./src/parcer.c ./src/parcer1.c ./src/parcer2.c \
			./src/get_next_line/get_next_line.c \
			./src/get_next_line/get_next_line_utils.c \

OBJS	= 	$(SRCS:.c=.o)

LIBFT	=	./src/libft/libft.a

MLX 	=	./src/mlx/libmlx.a

NAME	=	fdf

NAME_BONUS		= fdf_bonus

GCC		= 	gcc
RM		= 	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

all:		$(NAME)

bonus:		$(NAME_BONUS)

%.o:		%.c		
			$(GCC) $(CFLAGS) -c $< -o $@

$(NAME):	$(MLX) $(OBJS) $(LIBFT) ./src/fdf.h
			$(GCC) ./src/mlx/libmlx.a -framework OpenGL -framework AppKit $(OBJS) $(LIBFT) -o $(NAME)

$(NAME_BONUS):	$(MLX) $(OBJS) $(LIBFT) ./src/fdf.h
			$(GCC) -lmlx ./src/mlx/libmlx.a -framework OpenGL -framework AppKit $(OBJS) $(LIBFT) -o $(NAME_BONUS)

$(LIBFT):	
			make -C "./src/libft"

$(MLX):     
			make -C "./src/mlx"

clean:		
			$(RM) $(OBJS)
			make clean -C "./src/libft"
			# make clean -C "./src/mlx"

fclean:		clean
			$(RM) $(NAME)  screenshot.bmp
			make fclean -C "./src/libft"
			make clean -C "./src/mlx"

re:			fclean all

.PHONY:		all clean fclean re
