#include <stdio.h>

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5; 
    int i, pos, newValue;

    printf("Initial Array: ");
    printArray(arr, n);

    pos = 2;     
    newValue = 25;

    for (i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = newValue;
    n++;

    printf("After Insertion at index %d: ", pos);
    printArray(arr, n);

    pos = 1; 
    for (i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; 

    printf("After Deletion at index %d: ", pos);
    printArray(arr, n);

    return 0;
}
