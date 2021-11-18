NAME = philo

SRCS=	eating.c \
		ft_atoi.c \
		init_threads.c \
		main.c \
		routines.c \
		taking_forks.c \
		time.c

OBJ= ${SRCS:.c=.o}

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra

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
		@${RM} philo
		@${RM} srcs/*.o

re: fclean all

.PHONY: re fclean clean all