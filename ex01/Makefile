# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolewicki <nicolewicki@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 16:21:44 by nicolewicki       #+#    #+#              #
#    Updated: 2024/11/27 16:30:43 by nicolewicki      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++17

NAME = fixedpointnumber

SRCS = main.cpp \
	   Fixed.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re