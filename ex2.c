#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Usage: %s <n>\n", argv[0]);
		return 1;
	}
	int n = atoi(argv[1]);

	for (int i = 0; i < n; i++) {
		pid_t pid = fork();
		if (pid == 0) {
			printf("Child %d: PID=%d, PPID=%d\n", i, getpid(), getppid());
		}
		sleep(5);
		
	}

	for (int i = 0; i < n; i++) wait(NULL);

	printf("Process PID=%d finished\n", getpid());
	return 0;
}
