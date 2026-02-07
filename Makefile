CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

SRC = main.c file_utils.c graphics_utils.c utils.c mfa_utils.c surface_parser.c render.c
OBJDIR = obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
NAME = retromfa
MLXDIR = ./minilibx-linux
MLXFLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm
MLX = $(MLXDIR)/libmlx.a

all: $(NAME)

$(MLX):
	make -C $(MLXDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c mfa.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
	rmdir $(OBJDIR) 2>/dev/null || true
	make -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all re clean fclean
