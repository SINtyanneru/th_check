#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* thread_func(void* arg) {
	pause();
	return NULL;
}

int main() {
	printf("\n");

	pthread_t t;
	int count = 0;
	while (pthread_create(&t, NULL, thread_func, NULL) == 0) {
		count++;

		printf("\e[1F[  \e[32mOK\e[0m  ]%d\n", count);
	}

	printf("計測完了。\n");
	printf("最大スレッド数: %d\n", count);
	return 0;
}
