CC = gcc
CFLAGS = -Wall -Wextra -Werror 

SRC = client.c libft/ft_atoi.c libft/ft_isdigit.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/printpoint.c ft_printf/exa.c

SRS = server.c ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c ft_printf/ft_putstr.c ft_printf/printpoint.c ft_printf/exa.c libft/ft_calloc.c libft/ft_strlen.c libft/ft_memset.c

OBJC = ${SRC:.c=.o} 
OBJS = ${SRS:.c=.o}

NAME = client

all:	${NAME} server
		
${NAME}: $(OBJC)
	gcc -o client -Wall -Wextra -Werror ${OBJC} -fsanitize=address

server: $(OBJS)
	gcc -o server -Wall -Wextra -Werror ${OBJS} -fsanitize=address
	
clean:
	rm -f ${OBJC} ${OBJS}

fclean: clean
	rm -f ${NAME}
	rm -f server

re: fclean all