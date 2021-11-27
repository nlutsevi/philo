NAME = philo

SRCS=	eating.c \
		ft_atoi.c \
		init_threads.c \
		main.c \
		routines.c \
		time.c \
		death.c

OBJ= ${SRCS:.c=.o}

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJ}
			@ar -rc ${NAME} ${OBJ}
			${CC} $(CFLAGS) ${SRCS} -o philo

all:	${NAME}

clean:
		@${RM} ${OBJS} philo.dSYM

fclean:	clean
		@${RM} ${NAME}
		@${RM} *.o

re: fclean all

.PHONY: re fclean clean all