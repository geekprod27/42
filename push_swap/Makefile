CC = gcc
CFLAGS = -Wextra -Wall -Werror -g -fsanitize=address

SRC = push_swap.c atol.c mouv.c mouv2.c sort.c util.c sort2.c util2.c

OBJ = ${SRC:.c=.o} ${SRS:.c=.o}

NAME = push_swap
LIBPRINTF = printf/libftprintf.a
LIBFT = libft/libft.a

all:	${NAME}

${LIBPRINTF}:
		@make -C printf/

${LIBFT}:
	@make -C libft/

${NAME}: ${LIBPRINTF} ${LIBFT} ${OBJ}
	gcc -o ${NAME} ${OBJ} ${LIBPRINTF} ${LIBFT} -fsanitize=address

clean:
	rm -f ${OBJ}
	@make clean -C printf/
	@make clean -C libft/

fclean: clean
	rm -f ${NAME}
	@make fclean -C printf/
	@make fclean -C libft/

re: fclean all