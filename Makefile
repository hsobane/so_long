SRC = mandatory/map_utils/map_utils.c mandatory/parse_utils/parse_args.c \
	mandatory/string_utils/string_utils.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c mandatory/parse_utils/check_components.c \
	mandatory/parse_utils/check_dimension.c mandatory/parse_utils/check_path.c \
	mandatory/parse_utils/check_walls.c mandatory/parse_utils/flood_fill.c \
	mandatory/map_utils/map_utils2.c mandatory/mlx_utils/init_mlx.c \
	mandatory/mlx_utils/key_handler.c mandatory/mlx_utils/move_lplayer.c \
	mandatory/mlx_utils/move_gplayer.c mandatory/mlx_utils/mlx_utils.c \
	mandatory/so_long.c
OBJ = $(SRC:.c=.o)
BSRC = bonus/map_utils/map_utils.c bonus/parse_utils/parse_args.c \
	bonus/string_utils/string_utils.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c bonus/parse_utils/check_components.c \
	bonus/parse_utils/check_dimension.c bonus/parse_utils/check_path.c \
	bonus/parse_utils/check_walls.c bonus/parse_utils/flood_fill.c \
	bonus/map_utils/map_utils2.c bonus/mlx_utils/init_mlx.c \
	bonus/mlx_utils/key_handler.c bonus/mlx_utils/move_lplayer.c \
	bonus/mlx_utils/move_gplayer.c bonus/mlx_utils/mlx_utils.c \
	bonus/so_long.c
BOBJ = $(BSRC:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror
#MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
MLXFLAGS = mlx/libmlx_Linux.a -lXext -lX11 -lm
NAME = so_long
NAME_BONUS = so_long_bonus
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes 

all: $(NAME)

$(NAME): compile $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)
	@echo "Done!"

bonus: compile $(BOBJ)
	@$(CC) $(CFLAGS) $(BOBJ) $(MLXFLAGS) -o $(NAME_BONUS)
	@echo "Done!"

valgrind: $(NAME)
	@valgrind --log-file=valgrind.log $(VFLAGS) ./$(NAME) maps/map.ber
	
compile:
	@echo "Compiling..."

%.o: %.c mandatory/so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/so_long_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BOBJ)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re