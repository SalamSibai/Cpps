# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 19:37:45 by ssibai            #+#    #+#              #
#    Updated: 2024/12/28 19:37:48 by ssibai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	violence

FILES	=	main.cpp	\
			HumanA.cpp	\
			HumanB.cpp	\
			Weapon.cpp	\

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