CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

SRC = main.c file_utils.c graphics_utils.c utils.c mfa_utils.c
OBJ = $(SRC:.c=.o)
NAME = retromfa
MLXDIR = ./minilibx-linux
MLXFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm
MLX = $(MLXDIR)/libmlx.a

all: $(NAME)

$(MLX):
	make -C $(MLXDIR)

%.o: %.c mfa.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all re clean fclean
