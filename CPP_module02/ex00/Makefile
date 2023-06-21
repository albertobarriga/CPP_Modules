CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
		Harl.cpp

OBJ = $(SRCS:.cpp=.o)

RM = 	rm -f

NAME = harlFilter

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