NAME =		cub3D

SRCS =		src/raycast/main.c						src/raycast/init.c\
			src/raycast/raycast.c					src/raycast/draw_tex.c\
			src/raycast/events.c					src/raycast/utils.c\
			src/gnl/get_next_line.c					src/gnl/get_next_line_utils.c\
			src/parser/parser.c						src/parser/parser_check_type_data.c\
			src/parser/parser_get_file_data.c		src/parser/parser_get_map_data.c\
			src/parser/parser_get_map.c				src/parser/parser_get_type_data.c\
			src/parser/parser_store_file_data.c		src/parser/parser_utils.c

OBJS =		$(SRCS:.c=.o)

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

HEAD_DIR =	includes

HEADER =	$(HEAD_DIR)/cub3D.h		$(HEAD_DIR)/parser.h	$(HEAD_DIR)/get_next_line.h

LIBFT_DIR =	libft

LIBFT =		$(LIBFT_DIR)/libft.a

MLX_DIR =	mlx

MLX_LIB =	-lmlx -lX11 -lXext -lm

RM =		rm -f

all:		subsystem $(NAME)

%.o:		%.c $(HEADER) $(LIBFT)
			$(CC) $(CFLAGS) -I $(HEAD_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR) -c $< -o $@

subsystem:
			make -C $(LIBFT_DIR)
			make -C $(MLX_DIR)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ -L $(LIBFT_DIR) -lft -L $(MLX_DIR) $(MLX_LIB) -o $(NAME)

clean:
			$(RM) $(OBJS)
			make clean -C $(LIBFT_DIR)

fclean:		clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT_DIR)
			make clean -C $(MLX_DIR)

re:			fclean all

.PHONY:		all clean fclean re