SRC = mandatory/map_utils/map_utils.c mandatory/parse_utils/parse_args.c \
	mandatory/string_utils/string_utils.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c mandatory/parse_utils/check_components.c \
	mandatory/parse_utils/check_dimension.c mandatory/parse_utils/check_path.c \
	mandatory/parse_utils/check_walls.c mandatory/parse_utils/flood_fill.c \
	mandatory/map_utils/map_utils2.c mandatory/mlx_utils/init_mlx.c \
	mandatory/mlx_utils/key_handler.c mandatory/mlx_utils/move_lplayer.c \
	mandatory/mlx_utils/move_gplayer.c mandatory/so_long.c
OBJ = $(SRC:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror -Imlx
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long

CLANG = clang
CLANGFLAGS = -glldb -Wall -Wextra -Werror -Imlx

all: $(NAME)

debug:
	$(CLANG) $(CLANGFLAGS) $(MLXFLAGS) $(SRC) -o $(NAME)

$(NAME): compile $(OBJ)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) -o $(NAME)
	@echo "Done!"

compile:
	@echo "Compiling..."

%.o: %.c mandatory/so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re