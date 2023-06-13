CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Zombie.cpp \
		main.cpp \
		newZombie.cpp \
		randomChump.cpp

OBJ = $(SRCS:.cpp=.o)

RM = 	rm -f

NAME = zombie

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	

clean:
	$(RM) ${OBJ}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all, clean, fclean, re