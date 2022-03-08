CC = gcc
CFLAGS = -Wextra -Wall -Werror

SRC = philo.c

OBJ = ${SRC:.c=.o} ${SRS:.c=.o}

NAME = philo

all:	${NAME}

${NAME}: ${LIBPRINTF} ${LIBFT} ${OBJ}
	gcc -o ${NAME} ${OBJ} ${LIBPRINTF} ${LIBFT}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all