NAME = Intern
CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = 	main.cpp Bureaucrat.cpp AForm.cpp \
 		PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
		ShrubberyCreationForm.cpp Intern.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
