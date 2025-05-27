
NAME	=	Animal

FILES	=	main.cpp		\
			Animal.cpp		\
			Cat.cpp			\
			Dog.cpp			\
			Brain.cpp		\

CXX		=	c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g3

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