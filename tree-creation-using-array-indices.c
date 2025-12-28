#include <stdio.h>

#define MAX_SIZE 15 

char tree[MAX_SIZE];

void initTree() {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        tree[i] = '-'; 
    }
}

void setRoot(char key) {
    tree[0] = key;
}
void setLeft(char key, int parentIndex) {
    int leftChildIndex = (parentIndex * 2) + 1;
    if (tree[parentIndex] == '-') {
        printf("Error: Parent not found at index %d\n", parentIndex);
    } else if (leftChildIndex >= MAX_SIZE) {
        printf("Error: Tree limit reached\n");
    } else {
        tree[leftChildIndex] = key;
    }
}

void setRight(char key, int parentIndex) {
    int rightChildIndex = (parentIndex * 2) + 2;
    if (tree[parentIndex] == '-') {
        printf("Error: Parent not found at index %d\n", parentIndex);
    } else if (rightChildIndex >= MAX_SIZE) {
        printf("Error: Tree limit reached\n");
    } else {
        tree[rightChildIndex] = key;
    }
}

void printTree() {
    int i;
    printf("Array Representation: ");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%c ", tree[i]);
    }
    printf("\n");
}

int main() {
    initTree();

    setRoot('A');
    setLeft('B', 0);
    setRight('C', 0);
    setLeft('D', 1);
    setRight('E', 1);
    setRight('F', 2);

    printTree();

    return 0;
}
