#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
int width;

int main(int argc, char **argv) {
	int i = 0, j, r, c;
	if (argc < 2) {
		printf("%s <number of N>\n", argv[0]);
		return -1;
	}

	while (argv[1][i]) {
		if (argv[1][i] < '0' || argv[i][i] > '9') {
			printf("Invalid number\n");
			return -1;
		}
		N *= 10;
		N += argv[1][i] - '0';
		i++;
	}

	i = N * N;
	while (i) {
		i /= 10;
		width++;
	}

	printf("N=%d\n", N);
	if (N % 2 != 1) {
		printf("N must be odd number\n");
		return -1;
	}

	int (*buf)[N] = malloc(N*N*sizeof(int));
	memset(buf, 0, sizeof(N*N*sizeof(int)));
	i = 0;
	r = 0;
	c = N / 2;

	while (i < N * N) {
		if (buf[r][c]) {
			r = (r + 2) % N;
			c = (c + N - 1) % N;
		} else {
			buf[r][c] = i + 1;
			r = (r + N - 1) % N;
			c = (c + 1) % N;
			i++;
		}
	}

	for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			printf("%*d ", width, buf[i][j]);
		}
		printf("\n");
	}

	return 0;
}
