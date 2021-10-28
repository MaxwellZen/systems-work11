#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

	printf("Reading numbers...\n\n");
	int arr[10];
	int filea = open("/dev/random", O_RDONLY, 0777);
	read(filea, arr, 10*sizeof(int));

	printf("Original array:\n");
	for (int i = 0; i < 10; i++) {
		printf("\trandom %d: %d\n", i, arr[i]);
	}

	printf("\nWriting numbers to file...\n\n");
	int fileb = open("numbers.txt", O_CREAT | O_WRONLY, 0777);
	write(fileb, arr, 10*sizeof(int));

	printf("Reading numbers from file...\n\n");
	int filec = open("numbers.txt", O_RDONLY, 0777);
	int arr2[10];
	read(filec, arr2, 10*sizeof(int));

	printf("Copied array:\n");
	for (int i = 0; i < 10; i++) {
		printf("\trandom %d: %d\n", i, arr2[i]);
	}

}
