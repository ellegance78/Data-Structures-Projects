#include <stdio.h>

void convertToSparse(int row, int col, int matrix[4][5]) {
    int i, j, k; 
    int nonZeroCount = 0;
	for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }
    int sparse[100][3]; 
    sparse[0][0] = row;
    sparse[0][1] = col;
    sparse[0][2] = nonZeroCount;
    k = 1;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    printf("\nRow\tCol\tValue\n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
}
int main() {
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    convertToSparse(4, 5, matrix);
    return 0;
}
