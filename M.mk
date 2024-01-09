SRC = main.c
OBJ = $(SRC:.c=.o)
CC = cc -g
NAME = main
MLx = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): compile $(OBJ)
	@$(CC) $(OBJ) $(MLx) -o so_long
	@echo "Done!"

compile:
	@echo "Compiling..."

%.o: %.c
	@$(CC) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
