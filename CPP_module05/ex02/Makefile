CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = AForm.cpp\
		Bureaucrat.cpp\
		PresidentialPardonForm.cpp\
		RobotomyRequestForm.cpp\
		ShrubberyCreationForm.cpp\
		main.cpp

OBJ = $(SRCS:.cpp=.o)

RM = 	rm -f

NAME = Form

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	

clean:
	$(RM) ${OBJ}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all, clean, fclean, re