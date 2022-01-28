CC = gcc
CFLAGS = -Wextra -Wall -Werror

SRC = push_swap.c

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
	gcc -o ${NAME} ${OBJ} ${LIBPRINTF} ${LIBFT}

clean:
	rm -f ${OBJ}
	@make clean -C printf/
	@make clean -C libft/

fclean: clean
	rm -f ${NAME}
	@make fclean -C printf/
	@make fclean -C libft/

re: fclean all