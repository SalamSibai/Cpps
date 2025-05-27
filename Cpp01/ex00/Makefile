# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 19:33:28 by ssibai            #+#    #+#              #
#    Updated: 2024/12/28 19:42:22 by ssibai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombies

FILES = main.cpp 			\
		Zombie.cpp 			\
		newZombie.cpp		\
		randomChump.cpp		\

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

OBJS = $(FILES:.cpp=.o)

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o ${<:.cpp=.o}

all:	$(NAME)

$(NAME)	: $(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
