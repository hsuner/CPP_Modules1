NAME = main
CC = c++ -std=c++98
FLAGS = -Wall -Wextra -Werror
SRC =	main.cpp \
		newZombie.cpp \
		randomChamp.cpp \
		Zombie.cpp

OBJS = $(SRC:.cpp=.o)

GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \033[34;1m
RESET = \x1b[0m

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN) Executable named main created$(RESET)\n"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@printf "$(BLUE) deleting object files$(RESET)\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(RED) deleting executable main$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re