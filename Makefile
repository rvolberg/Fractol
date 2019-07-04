#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 10:05:54 by rvolberg          #+#    #+#              #
#    Updated: 2018/09/29 10:05:14 by rvolberg         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = fractol

CC = clang

FlAGS = -Wall -Werror -Wextra

SRC = 	\
main.c\
ft_fractal.c \
output.c \
option.c \
option_bis.c \
init.c

OBJ = $(SRC:.c=.o)

INCLUDE = -I ./include/

LIBFT_PATH = ./libft/

LIBFT_LINK = -L $(LIBFT_PATH) -lft

LIBFT = $(LIBFT_PATH)libft.a

MLX_PATH = /usr/local/

MLX = -I $(MLX_PATH)includes -L $(MLX_PATH)lib/ -lmlx

FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

libft_make :
	make -C $(LIBFT_PATH)

$(NAME) : libft_make $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT_LINK) $(MLX) $(FRAMEWORK)

%.c.o :
	$(CC) $(FLAGS) $(INCLUDE) -o $(SRC) -c $<

.PHONY : clean fclean

clean :
	/bin/rm -rf $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean : clean
	/bin/rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all
	make -C $(LIBFT_PATH) re