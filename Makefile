CLIENT = client
SERVER = server
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
SRCS_SERVER = ft_putnbr_fd.c ft_putchar_fd.c ft_atoi_base.c server.c
SRCS_CLIENT = ft_atoi.c client.c 
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}

all:  ${SERVER} ${CLIENT}

${SERVER}: ${OBJS_SERVER}
		${CC} ${CFLAGS} ${OBJS_SERVER} -o server
${CLIENT}: ${OBJS_CLIENT}
		${CC} ${CFLAGS} ${OBJS_CLIENT} -o client

clean:
		rm -rf client.o server.o ft_putnbr_fd.o ft_putchar_fd.o ft_atoi_base.o ft_atoi.o

fclean: clean
	${RM} ${CLIENT} ${SERVER}

re : fclean all

.PHONY: all clean fclean re