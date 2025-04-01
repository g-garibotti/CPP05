NAME = bureaucracy
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRCS = main.cpp \
       Bureaucrat.cpp \
       AForm.cpp \
       ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp \
       PresidentialPardonForm.cpp \
       Intern.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) *_shrubbery

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re