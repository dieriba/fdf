SRCS		= ./srcs/errors_handling.c ./srcs/fdf.c ./srcs/parsing.c 

OBJS		= $(SRCS:.c=.o)

DEPS		= $(SRCS:.c=.d)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -MMD

FDF		=	fdf

all:		$(FDF)

.c.o :	
			$(CC) -g3 $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FDF):		${OBJS}
			make -C ./libft/ft_printf
			cp ./libft/ft_printf/libprintf.a ./lib
			make -C ./libft
			cp ./libft/libft.a ./lib
			make -C ./libft/get_next_line
			cp ./libft/get_next_line/libgnl.a ./lib
			$(CC) $(CFLAGS) ${OBJS} -g3 -L./lib -lft -lprintf -lgnl -lm -o $(FDF)

clean:
			rm -rf ./srcs/*.o
			rm -rf ./srcs/*.d
			
fclean:		clean
			rm -rf $(FDF) ./lib/*.a

re:			fclean all

-include : $(DEPS)

.PHONY:		all clean fclean re