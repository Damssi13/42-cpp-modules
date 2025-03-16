NAME = zombie
CXX = c++ 
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra
SRCS = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp 
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re