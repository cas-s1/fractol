NAME = fractol

CFLAGS = -Wall -Wextra -Werror -w

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

LIBFT = libft/libft.a

MLX = mlx/libmlx.a

FUNCTIONS = fractol \

SRCDIR = src

SRC = $(SRCDIR)/$(FUNCTIONS:%=%.c)

OBJDIR = obj

OBJ = $(OBJDIR)/$(FUNCTIONS:%=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@cc $(CFLAGS) $(MLXFLAGS) $(OBJ) $(MLX) $(LIBFT) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@cc $(CFLAGS) -Imlx -c $< -o $@

$(LIBFT):
	@make -s re -C ./libft

$(MLX):
	@make -s re -C ./mlx

clean:
	@make -s fclean -C ./libft
	@make -s clean -C ./mlx
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
