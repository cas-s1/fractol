NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -c

FUNCTIONS = ft_atoi \
			ft_bzero \
			ft_calloc \
			ft_isalnum \
			ft_isalpha \
			ft_isascii \
			ft_isdigit \
			ft_isprint \
			ft_itoa \
			ft_memchr \
			ft_memcmp \
			ft_memcpy \
			ft_memmove \
			ft_memset \
			ft_putchar_fd \
			ft_putendl_fd \
			ft_putnbr_fd \
			ft_putstr_fd \
			ft_split \
			ft_strchr \
			ft_strdup \
			ft_striteri \
			ft_strjoin \
			ft_strlcat \
			ft_strlcpy \
			ft_strlen \
			ft_strmapi \
			ft_strncmp \
			ft_strnstr \
			ft_strrchr \
			ft_strtrim \
			ft_substr \
			ft_tolower \
			ft_toupper \

BONUS =		ft_lstadd_back \
			ft_lstadd_front \
			ft_lstclear \
			ft_lstdelone \
			ft_lstiter \
			ft_lstlast \
			ft_lstmap \
			ft_lstnew \
			ft_lstsize \

CFILES = $(FUNCTIONS:%=%.c)

OFILES = $(FUNCTIONS:%=%.o)

BONUS_CFILES = $(BONUS:%=%.c)

BONUS_OFILES = $(BONUS:%=%.o)

$(NAME):
	@cc $(CFLAGS) -c $(CFILES)
	@ar -rc $(NAME) $(OFILES)

all: $(NAME)

clean:
	@rm -rf $(OFILES) $(BONUS_OFILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

bonus: 
	@cc $(CFLAGS) -c $(CFILES) $(BONUS_CFILES)
	@ar -rc $(NAME) $(OFILES) $(BONUS_OFILES)

.PHONY: all clean fclean re bonus
