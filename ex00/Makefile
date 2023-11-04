# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faksouss <faksouss@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 14:08:13 by faksouss          #+#    #+#              #
#    Updated: 2023/11/04 14:10:10 by faksouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

NAME = scalar

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $^ -o $@

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re

.SILENT: $(OBJ) $(NAME) clean fclean re all
