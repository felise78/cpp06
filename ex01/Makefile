NAME 		= 	serializer
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRC_FILES	=	main.cpp \
				Serializer.cpp

OBJ_FILES 	=	$(SRC_FILES:.cpp=.o)
HEADERS 	=	Serializer.hpp \
				Data.hpp

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re