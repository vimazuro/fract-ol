# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 11:26:33 by vimazuro          #+#    #+#              #
#    Updated: 2025/02/19 11:33:14 by vimazuro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
SRC_DIR = .
LIBFT_INC_DIR = libft/include 
MLX42_INC_DIR = MLX42/include
LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
MLX42_DIR = MLX42/build/
MLX42_LIB = $(MLX42_DIR)libmlx42.a
HEADER = fractol.h
LIBFT_HEADERS = libft/include/libft.h libft/include/ft_printf.h

SRC_FILES = src/main.c src/calculate_fractal.c src/draw_fractal.c \
	    src/scroll_callback.c src/loop_hook.c src/ft_clear_window.c \
	    src/offset_zoom.c src/get_color.c src/print_error.c \
	    src/check_argv.c src/key_callback.c src/run_fractal.c \

OBJS = $(LIBFT_LIB) $(MLX42_LIB) $(SRC_FILES:.c=.o)

all: makelibft makeMLX42 $(NAME)

makelibft:
	$(MAKE) -C $(LIBFT_DIR)

makeMLX42:
	cmake -DDEBUG=1 -S MLX42 -B $(MLX42_DIR)
	cmake --build $(MLX42_DIR) -j4

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I$(LIBFT_INC_DIR) -I$(MLX42_INC_DIR) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX42_LIB) \
	-L $(MLX42_DIR) -lmlx42 -ldl -lglfw -pthread -lm

%.o: %.c $(HEADER) $(LIBFT_HEADERS) Makefile
	$(CC) $(CFLAGS) -I$(LIBFT_INC_DIR) -I$(MLX42_INC_DIR) -c $< -o $@

clean:
	rm -f $(SRC_FILES:.c=.o)
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(MLX42_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re makelibft makeMLX42
