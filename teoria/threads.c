// creamos un hilo que escribe x líneas en un archivo de texto

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void	*thread_routine(void *arg)
{
	int		fd;
	int		num_lines;
	char	*buf;

	num_lines = *((int *)arg);
	buf = "Nueva linea \n";
	printf("El hilo comienza a ejecutarse...\n");
	for (int i=0; i < num_lines; i++)
	{
		fd = open("ejemplo.txt", O_WRONLY|O_APPEND);
		write(fd, buf, strlen(buf));
		close(fd);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	pthread_t 	thread1;
	int			value;

	if (argc == 2)
	{
		value = atoi(argv[1]);
		// FUNCION PARA CREAR UN NUEVO THREAD
		// int pthread_create(pthread_t *thread, const pthread_attr_t *attr, 
		// void *(*start_routine)(void *), void *arg);
		if (pthread_create(&thread1, NULL, thread_routine, &value) != 0)
			return -1;

		// FUNCION QUE ESPERA A QUE EL HILO FINALICE
		// int pthread_join(pthread_t thread, void **value_ptr);
		pthread_join(thread1, NULL);
	}
	else
		printf("Introduzca el número de líneas como primer argumento\n");

	return 0;
}