# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 19:31:51 by ssibai            #+#    #+#              #
#    Updated: 2024/12/28 19:31:53 by ssibai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	manyzombies

FILES	=	main.cpp		\
			Zombie.cpp		\
			zombieHorde.cpp

CXX		=	c++

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