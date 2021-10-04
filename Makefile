NAME = fractol

MLX = -L minilibx -lmlx -framework OpenGL -framework AppKit

SRC_NAME = args.c display.c draw.c events.c fractol.c zoom.c
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))

GCC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) fractol.h
	@make -C libft
	@make -C minilibx
	@$(GCC) $(CFLAGS) $(OBJ) $(MLX) -L libft -lft -o $(NAME)
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(GCC) $(FLAG) -c $< -o $@

clean:
	@make -C libft clean
	@make -C minilibx clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	@make -C minilibx fclean
	@rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re