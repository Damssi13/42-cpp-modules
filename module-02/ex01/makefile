NAME = fixed
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -g
SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re : fclean all


.PHONY: clean