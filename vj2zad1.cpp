#include <stdio.h>
#include <stdlib.h>


int* fibonacci(int n) {
	if (n <= 0) return NULL;

	int* niz = (int*)malloc(n * sizeof(int));
	if (!niz) {
		printf("Greska);
		return NULL;
	}

	niz[0] = 1;
	if (n > 1) niz[1] = 1;

	for (int i = 2; i < n; ++i) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}

	return niz;
}

int main() {
	int n = 10;
	int* niz = fibonacci(n);
	if (niz) {
		for (int i = 0; i < n; ++i) {
			printf("%d ", niz[i]);
		}
		printf("\n");
		free(niz);
	}
	return 0;
}
