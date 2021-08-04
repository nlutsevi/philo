// Permite sincronizar un recurso(i.e. una variable) compartido entre hilos
// Para complitar gcc archivo.c -lpthread

#include <pthread.h>
#include <stdio.h>

static int count = 10;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void	*thread1_routine(void *unused)
{
	for (int i = 0; i < 10000; i++)
	{
		//cambiará la variable si el mutex no ha sido bloqueado por el otro hilo
		pthread_mutex_lock(&mutex);
		count++;
		//desbloquea el mutex
		pthread_mutex_unlock(&mutex);
	}
	return (0);
}

void	*thread2_routine(void *unused)
{
	for (int i = 0; i < 10000; i++)
	{
		//cambiará la variable si el mutex no ha sido bloqueado por el otro hilo
		pthread_mutex_lock(&mutex);
		count--;
		//desbloquea el mutex
		pthread_mutex_unlock(&mutex);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	pthread_t thread1, thread2;

	if (pthread_create(&thread1, NULL, thread1_routine, NULL) != 0)
		printf("Error \n thread1 cannot be created\n");

	if (pthread_create(&thread2, NULL, thread2_routine, NULL) != 0)
		printf("Error \n thread2 cannot be created\n");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Count value: %d\n", count);
}