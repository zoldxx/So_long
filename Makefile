# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:38:53 by dberreby          #+#    #+#              #
#    Updated: 2023/03/20 14:48:07 by dberreby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				= main.c get_next_line.c get_next_line_utils.c \
					create_map.c parsing.c move.c ft_printf.c init_game.c init_image.c \
					map_faisable.c inondation.c parsing_2.c

OBJ 			= $(SRC:.c=.o)

BONUS_SRC			= printmove.c create_map.c ft_printf.c get_next_line_utils.c get_next_line.c \
					init_game.c init_image_bonus.c inondation.c main_bonus.c map_faisable.c \
					move_bonus.c parsing_2_bonus.c parsing_bonus.c

BONUS_OBJ		= $(BONUS_SRC:.c=.o)


CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g
HEADERS 		= -I ./includes
NAME			= so_long
BONUS			= so_long_bonus

all:		path	$(NAME)

bonus:	path		$(BONUS)

path:
		make -C mlx-linux/


%.o: %.c
	$(CC) $(HEADERS) -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(HEADERS) -Lmlx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) $(HEADERS) -Lmlx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(BONUS)

clean:
				$(RM) $(OBJ) $(BONUS_OBJ)

fclean:			clean
					$(RM) $(NAME) $(BONUS)

re:				fclean $(NAME)

.PHONY:			all clean fclean re

