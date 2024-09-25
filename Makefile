CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
MLX42 = ./MLX42
LIBFT_LIB = $(LIBFT_DIR)/libft/libft.a
INCLUDES = -I./libft/libs -I./ -I$(MLX42)/include
LIBS = -L$(MLX42)/lib -lmlx42 -lglfw -ldl -lm -lpthread -L$(LIBFT) -lft

MAIN = main.c
EXEC = test

all: $(LIBFT_LIB) $(EXEC)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(EXEC): $(MAIN)
	$(CC) $(CFLAGS) $(INCLUDES) $(MAIN) $(LIBFT_LIB) -o $(EXEC) $(LIBS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(EXEC)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean flean re bonus
