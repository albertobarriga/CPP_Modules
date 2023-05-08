CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Contact.cpp\
		Phonebook.cpp\
		main.cpp

OBJ = $(SRCS:.cpp=.o)

RM = 	rm -f

NAME = PhoneBook

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	

clean:
	$(RM) ${OBJ}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all, clean, fclean, re