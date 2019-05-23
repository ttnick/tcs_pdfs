#include <stdio.h>
#include <stdlib.h>

void swap(int** ary, int i, int j) {
	(*ary)[i] += (*ary)[j];
	(*ary)[j] = (*ary)[i] - (*ary)[j];
	(*ary)[i] -= (*ary)[j];
}

void bubblesort(int** ary, int len) {
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = 0; j < len-(i+1); j++) {
			if ((*ary)[j] > (*ary)[j+1]) {
				swap(ary, j, j+1);
			}
		}
	}
}

void insertionsort(int** ary, int len) {
	int i, j, a;
	for (i = 1; i < len; i++) {
		a = (*ary)[i];
		j = i;
		while (j > 0 && (*ary)[j-1] > a) {
			(*ary)[j] = (*ary)[j-1];
			j--;
		}
		(*ary)[j] = a;
	}
}

void selectionsort(int** ary, int len) {
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = i+1; j < len; j++) {
			if ((*ary)[i] > (*ary)[j]) {
				swap(ary, i, j);
			}
		}
	}
}

void merge(int** ary, int l, int m, int r) {
	int i, j, k;
	int left[m-l+1];
	int right[r-m];

	for (i = 0; i < m-l+1; i++) {
		left[i] = (*ary)[l+i];
	}
	for (j = 0; j < r-m; j++) {
		right[j] = (*ary)[m+j+1];
	}

	i = 0;
	j = 0;
	k = l;
	while (i < m-l+1 && j < r-m) {
		if (left[i] <= right[j]) {
			(*ary)[k] = left[i];
			i++;
		} else {
			(*ary)[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < m-l+1) {
		(*ary)[k] = left[i];
		i++;
		k++;
	}
	while (j < r-m) {
		(*ary)[k] = right[j];
		j++;
		k++;
	}
}

void mergesort(int** ary, int l, int r) {
	int m;
	if (l < r) {
		m = l+(r-l)/2;
		mergesort(ary, l, m);
		mergesort(ary, m+1, r);
		merge(ary, l, m, r);
	}
}

void quicksort(int** ary, int L, int R) {
	int p, l, r, tmp;
	if (R > L) {
		p = (*ary)[L];
		l = L;
		r = R+1;

		do {
			do {
				l++;
			} while ((*ary)[l] < p && l < r);
			do {
				r--;
			} while ((*ary)[r] > p);
			swap(ary, l, r);
		} while (l < r);

		tmp = (*ary)[r];
		(*ary)[L] = (*ary)[l];
		(*ary)[l] = tmp;
		(*ary)[r] = p;
		quicksort(ary, L, r-1);
		quicksort(ary, r+1, R);
	}
}

void heapify(int** ary, int len, int i) {
	int max = i;
	int l = 2*i+1;
	int r = 2*i+2;
	
	if (l < len && (*ary)[l] > (*ary)[max]) {
		max = l;
	}
	if (r < len && (*ary)[r] > (*ary)[max]) {
		max = r;
	}

	if (max != i) {
		swap(ary, i, max);
		heapify(ary, len, max);
	}
}

void heapsort(int** ary, int len) {
	int i;
	for (i = len/2-1; i >= 0; i--) {
		heapify(ary, len, i);
	}
	for (i = len-1; i >= 0; i--) {
		swap(ary, 0, i);
		heapify(ary, i, 0);
	}
}

void radixsort(int** ary, int len) {
	int i, j, k;
	int n[2] = {0, 0};
	int part[2][len];

	for (i = 0; i < 32; i++) {
		n[0] = 0;
		n[1] = 0;

		for (j = 0; j < len; j++) {
			k = ((*ary)[j] >> i) & 1;
			part[k][n[k]++] = (*ary)[j];
		}

		for (j = 0; j < n[0]; j++) {
			(*ary)[j] = part[0][j];
		}
		for (j = 0; j < n[1]; j++) {
			(*ary)[j+n[0]] = part[1][j];
		}
	}
}

void print_array(int* ary, int len) {
	int i;
	printf("[");
	for (i = 0; i < len; i++) {
		printf("%d, ", ary[i]);
	}
	printf("\b\b]\n");
}

int main(int argc, char** argv) {
	int i;
	int* ary = malloc((argc-1) * sizeof(int));

	if (ary == NULL) {
		return 1;
	}

	for (i = 0; i < argc-1; i++) {
		*(ary+i) = atoi(argv[i+1]);
	}

	print_array(ary, argc-1);

	//bubblesort(&ary, argc-1);
	//insertionsort(&ary, argc-1);
	//selectionsort(&ary, argc-1);
	//mergesort(&ary, 0, argc-2);
	//quicksort(&ary, 0, argc-2);
	//heapsort(&ary, argc-1);
	radixsort(&ary, argc-1);

	print_array(ary, argc-1);

	free(ary);

	return 0;
}
