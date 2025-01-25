# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 00:52:34 by zaiicko           #+#    #+#              #
#    Updated: 2025/01/25 19:15:26 by zaiicko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
INC_DIR = inc
INC = -I$(INC_DIR)
SRC_DIR = srcs
OBJ_DIR = obj
RM = rm -rf

SRCS =	main.c\
	utils.c\
	args_managing.c\
	init_data.c\
	thread_managing.c\
	routine.c\
	monitor.c\
	utils2.c\

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: logo $(NAME)

$(NAME):	$(OBJ)
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

clean:
		@$(RM) $(OBJ_DIR)

fclean: clean
		@$(RM) $(NAME)

re:	fclean all

logo:
	@echo "\033[31m"
	@echo "                                       "
	@echo " _|_|_|    _|        _|  _|            "
	@echo " _|    _|  _|_|_|        _|    _|_|    "
	@echo " _|_|_|    _|    _|  _|  _|  _|    _|  "
	@echo " _|        _|    _|  _|  _|  _|    _|  "
	@echo " _|        _|    _|  _|  _|    _|_|    "
	@echo "                                       "

.PHONY: fclean re all clean logo
