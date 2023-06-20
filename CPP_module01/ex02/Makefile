CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp

OBJ = $(SRCS:.cpp=.o)

RM = 	rm -f

NAME = brain

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) ${OBJ}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all, clean, fclean, re