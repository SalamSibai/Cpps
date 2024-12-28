# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssibai < ssibai@student.42abudhabi.ae>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 14:19:51 by ssibai            #+#    #+#              #
#    Updated: 2024/12/28 14:45:20 by ssibai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = phonebook

FILES = main.cpp 						\
		Contact.cpp 					\
		PhoneBook.cpp

CXX		=	c++

CXXFLAGS=	-Wall -Wextra -Werror -std=c++98

OBJS	=	$(FILES:.cpp=.o)

.cpp.o:
			$(CXX) $(CXXFLAGS) -c $< -o ${<:.cpp=.o}

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
			/bin/rm -f $(OBJS)

fclean:		clean
			/bin/rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus