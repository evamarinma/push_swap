CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
HEADER = libft.h
GNL_HEADER = ft_gnl/get_next_line.h
SRC = ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_isalnum.c ft_strrchr.c ft_split.c ft_itoa.c ft_strcmp.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putnbr_fd.c ft_putendl_fd.c \
	ft_printf/ft_get_address.c \
	ft_printf/ft_low_hex.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_putchar.c \
	ft_printf/ft_putnbr_u.c \
	ft_printf/ft_putnbr.c \
	ft_printf/ft_putstr.c \
	ft_printf/ft_up_hex.c \
	ft_gnl/get_next_line_utils.c \
	ft_gnl/get_next_line.c
BONUS_SRC = ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstiter.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
NAME = libft.a

all: $(NAME)


$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(BONUS_OBJ) $(NAME)
	ar rcs $(NAME) $(BONUS_OBJ)
	
%.o: %.c $(HEADER) $(GNL_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus