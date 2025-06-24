
NAME	=	btc

FILES	=	main.cpp		\
			RPN.cpp

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