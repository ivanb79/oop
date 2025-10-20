#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* data;
	int size;      
	int capacity;  
} Vector;

Vector* vector_new(int init_capacity) {
	Vector* v = (Vector*)malloc(sizeof(Vector));
	v->data = (int*)malloc(init_capacity * sizeof(int));
	v->size = 0;
	v->capacity = init_capacity;
	return v;
}

void vector_delete(Vector* v) {
	if (v) {
		free(v->data);
		free(v);
	}
}

void vector_push_back(Vector* v, int value) {
	if (v->size >= v->capacity) {
		v->capacity *= 2;
		v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
	}
	v->data[v->size++] = value;
}

void vector_pop_back(Vector* v) {
	if (v->size > 0)
		v->size--;
}

int vector_front(Vector* v) {
	return (v->size > 0) ? v->data[0] : -1;
}

int vector_back(Vector* v) {
	return (v->size > 0) ? v->data[v->size - 1] : -1;
}

int vector_size(Vector* v) {
	return v->size;
}


int main() {
	Vector* v = vector_new(4);

	for (int i = 1; i <= 10; ++i) {
		vector_push_back(v, i * 10);
	}

	printf("Vektor: ");
	for (int i = 0; i < vector_size(v); ++i) {
		printf("%d ", v->data[i]);
	}
	printf("\n");

	printf("Front: %d\n", vector_front(v));
	printf("Back: %d\n", vector_back(v));
	vector_pop_back(v);
	printf("Size nakon pop: %d\n", vector_size(v));

	vector_delete(v);
	return 0;
}
