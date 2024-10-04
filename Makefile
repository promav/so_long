# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabromer <pabromer@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 09:55:19 by pabromer          #+#    #+#              #
#    Updated: 2024/10/04 18:16:37 by pabromer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = ./libft
MLX42 = ./MLX42
LIBFT_LIB = $(LIBFT_DIR)/libft/libft.a
INCLUDES = -I./libft/libs -I./ -I$(MLX42)/include
LIBS = -L$(MLX42)/lib -lmlx42 -lglfw -ldl -lm -lpthread
SRCS = src/map_creator.c src/map_coor.c \
      src/map_errors1.c src/map_errors2.c src/map_errors_aux.c \
      src/init.c src/image_to_window.c src/moves1.c src/moves2.c \
      src/end.c src/main.c 
OBJS = $(SRCS:src/%.c=obj/%.o)
NAME = so_long


all: $(LIBFT_LIB) obj $(NAME)

obj:
	@mkdir -p obj

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_LIB) -o $(NAME) $(LIBS)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf obj

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
