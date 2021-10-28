#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	
	int arr[10];
	int filea = open("/dev/random", O_RDONLY, 0777);
	read(filea, arr, 10*sizeof(int));

	printf("Original array:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d: %d\n", i, arr[i]);
	}

	int fileb = open("numbers.txt", O_CREAT | O_WRONLY, 0777);
	write(fileb, arr, 10*sizeof(int));

	int filec = open("numbers.txt", O_RDONLY, 0777);
	int arr2[10];
	read(filec, arr2, 10*sizeof(int));

	printf("\nCopied array:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d: %d\n", i, arr2[i]);
	}

}
