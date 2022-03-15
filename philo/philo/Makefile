CC = gcc
CFLAGS = -Wextra -Wall -Werror -fsanitize=thread

SRC = philo.c util.c four.c main.c

OBJ = ${SRC:.c=.o} ${SRS:.c=.o}

NAME = philo

all:	${NAME}

${NAME}: ${LIBPRINTF} ${LIBFT} ${OBJ}
	gcc -o ${NAME} ${OBJ} ${LIBPRINTF} ${LIBFT} -lpthread -D_REENTRANT -fsanitize=thread

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all