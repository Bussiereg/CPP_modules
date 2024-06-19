NAME := Fixed2
FILES := Fixed main
OBJ_DIR := build

OBJ	:= $(addprefix $(OBJ_DIR)/, $(FILES:=.o))

CFLAGS := -Wall -Werror -Wextra -std=c++98
CC := c++
RM := rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:	
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: clean all