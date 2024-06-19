NAME := FragTrap
FILES :=  main ClapTrap ScavTrap FragTrap
OBJ_DIR := build
OBJ	:= $(addprefix $(OBJ_DIR)/, $(FILES:=.o))
FLAGS := -Wall -Werror -Wextra -std=c++98
CC := c++
RM := rm -rf


all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:	
	@$(RM) $(OBJ_DIR) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: clean all
