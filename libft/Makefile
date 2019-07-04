#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvolberg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/14 13:48:59 by rvolberg          #+#    #+#              #
#    Updated: 2018/09/29 10:06:52 by rvolberg         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = \
ft_memset.c\
ft_memcpy.c\
ft_memccpy.c\
ft_memmove.c\
ft_memchr.c\
ft_bzero.c\
ft_memcmp.c\
ft_strlen.c\
ft_strdup.c\
ft_strcpy.c\
ft_strncpy.c\
ft_strcat.c\
ft_strncat.c\
ft_strlcat.c\
ft_strchr.c\
ft_strrchr.c\
ft_strstr.c\
ft_strnstr.c\
ft_strcmp.c\
ft_strncmp.c\
ft_atoi.c\
ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_toupper.c\
ft_tolower.c\
ft_memalloc.c\
ft_memdel.c\
ft_strnew.c\
ft_strdel.c\
ft_strclr.c\
ft_striter.c\
ft_striteri.c\
ft_strmap.c\
ft_strmapi.c\
ft_strequ.c\
ft_strnequ.c\
ft_strsub.c\
ft_strjoin.c\
ft_strtrim.c\
ft_strsplit.c\
ft_itoa.c\
ft_putchar.c\
ft_putstr.c\
ft_putendl.c\
ft_putnbr.c\
ft_putchar_fd.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_lstnew.c\
ft_lstdelone.c\
ft_lstdel.c\
ft_lstadd.c\
ft_lstiter.c\
ft_lstmap.c\
my_isspace.c\
my_strlower.c\
my_strupper.c\
ft_sqrt.c\
ft_swap.c\
ft_strsub_free.c\
ft_strjoin_free.c\
get_next_line.c\
ft_open.c

OBJECTS = $(SRC:.c=.o)


INCLUDE = -I .

FLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME):
	gcc -c $(FLAGS) $(INCLUDE) $(SRC)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

.PHONY : clean fclean

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:fclean all