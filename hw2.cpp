/* Name: Kai Li Jin
 * Date: September 17, 2018
 * Description: This program prompts the user to enter an array of 20 elements (integers), and sorts them using two methods: insertion sort and merge sort.
 */

#include <iostream>
#include <math.h>
using namespace std;

void insertion_sort(int A[]);
void merge_sort(int, int, int*);
void merge(int, int, int, int*);

int MAX = 5;

int main() {

	int A[MAX];
	
	// Prompt user to enter an array of 20 integers
	cout << "Fill the array with 5 integers: ";
	for (int i = 0; i < MAX; i++) {
		cout << i + 1 << ") ";
		cin >> A[i];
	}
	cout << endl;

	// Show the user the full array they entered
	cout << "The array you entered is: ";
	for (int j = 0; j < MAX; j++) {
		cout << A[j] << " ";
	}
	cout << endl;



	// Pass array to insertion sort
	cout << endl;
	cout << "Insertion Sort: ";
	insertion_sort(A);
	cout << endl;

	// Pass array to merge sort
	cout << endl;
	cout << "Merge Sort: ";
	merge_sort(0, MAX, A);
	cout << endl;

	return 0;
}

void insertion_sort(int A[]) {
	// Storing the current element whose left side is checked for its correct position	
	int I[MAX];

	// Copying array A to array I, so that original array A stays the same and can be used again to sort via merge method
	for (int a = 0; a < MAX; a++) {
		I[a] = A[a];
	}

	for (int i = 0; i < MAX; i++) {
		int temp = I[i];
		int j = i;

		// Check whether the adjacent element in the left side is greater or less than the current element
		while (j > 0 && I[j - 1] > temp) {

			// Moving the left side element one position forward
			I[j] = I[j - 1];
			j--;
		}

		// Moving the current element to its correct position
		I[j] = temp;

	}

	// Display sorted array
	for (int k = 0; k < MAX; k++) {
		cout << I[k] << " ";
	}
	cout << endl;	

}

// Merge sort is a work in progress

void merge_sort(int low, int high, int* p) {
	int pivot;

	static int i(1);

	if (high > low) {
		pivot = low + ((high - low)/2);
		merge_sort(low, pivot, p);
		merge_sort(pivot + 1, high, p);
		merge(low, pivot, high, p);
	}
}

void merge(int l, int pi, int h, int* M) {
	int start = l;
	int mid = pi + 1;

	while ((start <= pi) && (mid <= h)) {
		if (M[start] > M[mid]) {
			int temp = M[mid];
			M[mid] = M[start];
			M[start] = temp;
			mid++;
		}

		else {
			start++;
		}
	}
}


/*
void merge_sort(int A[], int high, int low) {
	int mid;

	if (low < high) {
		mid = (high+low)/2;		// Avoids overflow when low, high are too large
		merge_sort(A, low, mid);
		merge_sort(A, mid + 1, high);
		merge(A, low, mid, high);
	}
}

void merge(int A[], int low, int mid, int high) {
	int h, i, j, b[MAX], k;
	h = low;
	i = low;
	j = mid + 1;

	int M[MAX];

	// Copying array A to array M, so that array A stays the same and an be used again to sort via insertion method.
	for (int a = 0; a < MAX; a++) {
		M[a] = A[a];
	}

	while ((h <= mid) && (j <= high)) {
		if (M[h] <= M[j]) {
			b[i] = M[h];
			h++;
		}

		else {
			b[i] = M[j];
			j++;
		}

		i++;
	}

	if (h > mid) {
		for (k = j; k <= high; k++) {
			b[i] = M[k];
			i++;
		}
	}

	else {
		for (k = h; k <= mid; k++) {
			b[i] = M[k];
			i++;
		}
	}

	for (k = low; k <= high; k++) {
		M[k] = b[k];
	}

	for (int y = 0; y <= MAX; y++) {
		cout << M[y] << " ";
	}
	cout << endl;
	

}

void merge_sort(int A[]) {
	
	int M[MAX];

	// Copying array A to array M, so that array A stays the same and an be used again to sort via insertion method.
	for (int a = 0; a < MAX; a++) {
		M[a] = A[a];
	}

	int p, q, r;
	p = 0;
	q = MAX/2;
	r = MAX;

	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}

	for (int j = 0; j < n2; j++) {
		R[j] = A[q + 1 + j];
	}

	// Maintain current index of subarrays and main array
	int i, j, k;
	i = 0;
	j = 0;
	k = p;

	// Until we reach either the end of either L or R, pick larger among elements L and R and place them in the correct position at A[p..r]
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			M[k] = L[i];
			i++;
		}

		else {
			M[k] = R[j];
			j++;
		}

		k++;
	}

	// When we run out of elements in either L or R, pick up the remaining elements and put them in A[p..r]
	while (i < n1) {
		M[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		M[k] = R[j];
		j++;
		k++;
	}

	// Display sorted array
	for (int k = 0; k < MAX; k++) {
		cout << M[k] << " ";
	}
*/









