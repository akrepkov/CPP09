
SRC = main.cpp RPN.cpp
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror 
HEADER = RPN.hpp

NAME = RPN

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp  $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)
