NAME = replacing
CXX = c++ 
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra -g
SRCS = main.cpp Sed.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean 