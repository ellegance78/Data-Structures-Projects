#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;    
    int sol = 2 * i + 1; 
    int sag = 2 * i + 2; 

    if (sol < n && arr[sol] > arr[largest])
        largest = sol;

    if (sag < n && arr[sag] > arr[largest])
        largest = sag;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int sol = 2 * i + 1;
    int sag = 2 * i + 2;

    if (sol < n && arr[sol] < arr[smallest])
        smallest = sol;

    if (sag < n && arr[sag] < arr[smallest])
        smallest = sag;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
    printf("Max-Heap dizisi: ");
    printArray(arr, n);

    for (i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
    printf("Min-Heap dizisi: ");
    printArray(arr, n);

    return 0;
}
