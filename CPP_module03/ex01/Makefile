CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ClapTrap.cpp\
		ScavTrap.cpp\
		main.cpp

OBJ = $(SRCS:.cpp=.o)

RM = 	rm -f

NAME = claptrap

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