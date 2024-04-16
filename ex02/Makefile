NAME 		= 	base
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

SRC_DIR		=	src/
OBJ_DIR		=	obj/
INC_DIR		=	inc/

SRC_FILES	=	main.cpp 

OBJ_FILES 	=	$(SRC_FILES:.cpp=.o)

HEADERS 	=	Base.hpp \
				A.hpp \
				B.hpp \
				C.hpp \
				layout.hpp

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
INC 		= 	$(addprefix $(INC_DIR), $(HEADERS))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp $(INC)
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re