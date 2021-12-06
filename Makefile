NAME = philo

SRCS=	srcs/eating.c \
		srcs/libft_utils.c \
		srcs/init_threads.c \
		srcs/main.c \
		srcs/routines.c \
		srcs/time.c \
		srcs/death.c

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
		@${RM} ${OBJ} philo.dSYM

fclean:	clean
		@${RM} ${NAME}
		@${RM} *.o

re: fclean all

.PHONY: re fclean clean all