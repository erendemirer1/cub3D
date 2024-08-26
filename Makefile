NAME = cub3D
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = main.c init.c game/game.c game/movement.c game/rotation.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		exit_and_frees/free1.c libft/utils.c \
		libft/utils2.c libft/utils3.c \
		map/map_checker.c map/map_init1.c map/map_init2.c map/pathfinder.c\
		map/set_texture_and_color.c \
		raycasting/raystart.c raycasting/mathematics.c raycasting/mathematics2.c \
		raycasting/draw.c exit_and_frees/free2.c \

OBJ = $(SRC:.c=.o)

MINILIBX_PATH = ./minilibx
MINILIBX = $(MINILIBX_PATH)/libmlx.a
MINILIBX_FLAGS = -L$(MINILIBX_PATH) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJ)	
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MINILIBX) $(MINILIBX_FLAGS)
	@echo "\033[0;32m KAD/ER Cub3D compiled \033[0m [✓]"

$(MINILIBX):
	@make -C $(MINILIBX_PATH)

clean:
	@make clean -C $(MINILIBX_PATH)
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

kader: all clean

norminette :
	@find . -type f \( -name "*.c" -o -name "*.h" \) ! -path "$(MINILIBX_PATH)/*" -exec norminette {} +

.PHONY: all clean fclean re
