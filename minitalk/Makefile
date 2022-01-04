SRC = client.c libft/ft_atoi.c libft/ft_isdigit.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/printpoint.c ft_printf/exa.c

SRS = server.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/printpoint.c ft_printf/exa.c

OBJ = ${SRC:.c=.o} ${SRS:.c=.o}

NAME = client


all:	${NAME} server
		
${NAME}:
	gcc -o client -Wall -Wextra -Werror ${SRC}

server:
	gcc -o server -Wall -Wextra -Werror ${SRS}
	
clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}
	rm -f server

re: fclean alls