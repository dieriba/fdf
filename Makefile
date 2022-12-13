SRCS		= ./srcs/errors_handling.c ./srcs/fdf.c ./srcs/parsing.c ./srcs/parsing_utils.c ./srcs/init.c ./srcs/mlx_hooks.c ./srcs/image.c

OBJS		= $(SRCS:.c=.o)

DEPS		= $(SRCS:.c=.d)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -MMD

MLX_FLAGS	= mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11  

FDF		=	fdf

all:		$(FDF)

.c.o :	
			$(CC) -g3 $(CFLAGS) -c $< -o $@

$(FDF):		${OBJS}
			make -C ./libft/ft_printf
			cp ./libft/ft_printf/libprintf.a ./lib
			make -C ./libft
			cp ./libft/libft.a ./lib
			make -C ./libft/get_next_line
			cp ./libft/get_next_line/libgnl.a ./lib
			$(CC) $(CFLAGS) ${OBJS} -g3 -L./lib -lft -lprintf -lgnl -lm $(MLX_FLAGS) -o $(FDF)

clean:
			rm -rf ./srcs/*.o
			rm -rf ./srcs/*.d
			
fclean:		clean
			make -C ./libft/ft_printf fclean
			make -C ./libft/get_next_line fclean
			make -C ./libft/ fclean
			rm -rf $(FDF) ./lib/*.a

re:			fclean all

-include : $(DEPS)

.PHONY:		all clean fclean re