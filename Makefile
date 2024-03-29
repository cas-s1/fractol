NAME := fractol

OS := $(shell uname)

ifeq ($(OS), Linux)
	MLXDIR := mlx_linux
	MLXNAME := mlx_Linux
	INC := -I/usr/include -I$(MLXDIR) -I./inc
	MLX := $(MLXDIR)/lib$(MLXNAME).a
	MLXFLAGS := -L$(MLXDIR) -l$(MLXNAME) -L/usr/lib -lXext -lX11 -lm -lz

else
	MLXDIR := mlx_macos
	MLXNAME := mlx
	INC := -I$(MLXDIR) -I./inc
	MLX := $(MLXDIR)/lib$(MLXNAME).a
	MLXFLAGS := -L$(MLXDIR) -l$(MLXNAME) -framework OpenGL -framework Appkit
endif

CFLAGS := -Wall -Wextra -Werror -O3

LIBFT := libft/libft.a

FILES := fractol \
		 math \
		 utils \
		 mandelbrot \
		 julia \
		 burningship \
		 colours \
		 events \

SRCDIR := src

SRC := $(FILES:%=$(SRCDIR)/%.c)

OBJDIR := obj

OBJ := $(FILES:%=$(OBJDIR)/%.o)

NOPRINT = 1> /dev/null 2> /dev/null

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@cc $(CFLAGS) $(MLXFLAGS) $(OBJ) $(MLX) $(LIBFT) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@cc $(CFLAGS) $(INC) -c $< -o $@

$(LIBFT):
	@make -sC ./libft

$(MLX):
	@make -sC ./$(MLXDIR) --no-print-directory $(NOPRINT)

clean:
	@make -s fclean -C ./libft
	@make -s clean -C ./$(MLXDIR) $(NOPRINT)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
