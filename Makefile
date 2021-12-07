# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 12:35:41 by dchonvil          #+#    #+#              #
#    Updated: 2021/07/30 04:57:50 by dchonvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MK = make

CC = clang

RM = rm -rf

LIB = libft.a

NAME = push_swap

SPATH = ./srcs/

BPATH = ./bonus/

LIB_PATH = ./libft/

SRC = $(SPATH)*.c

SRC_BNS = $(BPATH)*.c

HEAD_PATH = -I inc -I libft/inc

LDFLAGS = $(LIB_PATH)$(LIB)

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

OBJ_BNS = $(SRC_BNS:.c=.o)

OBJ_DIR = mkdir obj && mv *.o obj

.c.o:
	$(CC) $(CFLAGS) $(HEAD_PATH) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(MK) -C libft
	$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(HEAD_PATH)
	(cd $(SPATH) && $(OBJ_DIR))

clean:
	$(MK) clean -C libft
	(cd $(SPATH) && $(RM) obj)

fclean: clean
	$(RM) $(NAME)
	$(MK) fclean -C libft

bonus: fclean $(OBJ_BNS)
	$(MK) -C libft
	$(CC) $(SRC_BNS) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(HEAD_PATH)
	(cd $(BPATH) && $(OBJ_DIR))

re: fclean all

