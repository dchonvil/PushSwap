# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchonvil <dchonvil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 12:35:41 by dchonvil          #+#    #+#              #
#    Updated: 2021/12/18 02:23:56 by dchonvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MK = make

CC = clang

RM = rm -rf

LIB = libft.a

NAME = push_swap

BNS = checker

SPATH = ./srcs/

BPATH = ./bonus/

LIB_PATH = ./libft/

SRC = $(SPATH)biga.c \
	$(SPATH)ps_utils.c \
	$(SPATH)actions.c \
	$(SPATH)check_args.c \
	$(SPATH)check_list.c \
	$(SPATH)check_moves.c \
	$(SPATH)pushswap.c \
	$(SPATH)sobiga.c

SRC_BNS = $(BPATH)ps_utils_bonus.c \
	$(BPATH)actions_bonus.c \
	$(BPATH)check_args_bonus.c \
	$(BPATH)check_list_bonus.c \
	$(BPATH)check_moves_bonus.c \
	$(BPATH)checker_bonus.c \
	$(BPATH)intrp_bonus.c

HEAD_PATH = -I inc -I libft/inc

LDFLAGS = $(LIB_PATH)$(LIB)

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

OBJ_BNS = $(SRC_BNS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) $(HEAD_PATH) -c $< -o ${<:.c=.o}

all: $(LIB) $(NAME)

$(LIB):
	$(MK) -C libft

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(HEAD_PATH)

clean:
	$(MK) clean -C libft
	(cd $(SPATH) && $(RM) *.o)
	(cd $(BPATH) && $(RM) *.o)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BNS)
	$(MK) fclean -C libft

bonus:	$(OBJ_BNS)
	$(CC) $(SRC_BNS) -o $(BNS) $(CFLAGS) $(LDFLAGS) $(HEAD_PATH)

re: fclean all

