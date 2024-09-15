
NAME = phonebook

FILES = main.cpp 				\
		Contact.cpp 			\
		PhoneBook.cpp			\
		phonebook_utils.cpp		\
		add_contact_utils.cpp	\
		search_utils.cpp		\

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