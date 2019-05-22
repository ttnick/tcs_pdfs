#include <stdio.h>
#include <stdlib.h>

int h(int a, int b, int p, int x) {
	return ((a * x + b) % p) % 4;
}

int collisions(int x, int y, int p) {
	int a, b;
	int	count = 0;
	for (a = 1; a < 5; a++) {
		for (b = 0; b < 5; b++) {
			if (h(a, b, p, x) ==  h(a, b, p, y)) {
				count++;
			}
		}
	}
	return count;
}

void table(int p) {
	int x, y;
	for (x = 0; x < p; x++) {
		for (y = 0; y < p; y++) {
			printf("%d ", collisions(x, y, p));
		}
		printf("\n");
	}
}

int main(int argc, char** argv) {
	int i, p;
	for (i = 1; i < argc; i++) {
		p = atoi(argv[i]);
		printf("p = %d, divide by %d\n", p, p*(p-1));
		table(p);
		printf("\n");
	}
	return 0;
}
