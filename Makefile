#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkozhemi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/06 17:38:22 by vkozhemi          #+#    #+#              #
#    Updated: 2018/04/14 17:47:49 by nkuchyna         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	fillit

SRC		= main.c  \
		  ft_centre_tetr.c   \
		  ft_check_place.c \
		  ft_check_str.c \
		  ft_check_tetr.c \
		  ft_clean_tetr.c \
		  ft_clear_array.c \
		  ft_create_and_fill_srtruct_array.c \
		  ft_createarray.c \
		  ft_fill_array_by_tetr.c \
		  ft_maxx.c \
		  ft_maxy.c \
		  ft_printarray_charx2.c \
		  ft_putstr.c \
		  ft_solve_general.c \
		  ft_sqrt.c \
		  ft_step_back.c \
		  ft_strnew.c \
		  ft_slen.c \

INCLUDE = fillitft.h
OBJ  = $(SRC:.c=.o)
CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
			gcc -o $(NAME) $(CFLAGS) $(OBJ)

$(OBJ): %.o: %.c
			gcc -c $< -o $@ $(CFLAGS)

clean:
			rm -f $(OBJ)

fclean: clean
			rm -f $(NAME)

re: fclean all
