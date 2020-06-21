#include <stdio.h>



void toDiagonal(int matrix[][4], int r, int c,int i) {
	int temp = 1;
	for (int k = 0; k < r; k++) {
		if (k == i) continue;
		else {
			temp = matrix[k][i];
			for (int j = i; j < c; j++) {
				matrix[k][j] = matrix[k][j] - temp * matrix[i][j];
			}
		}
	}
}

void gaussJordanElimination(int matrix[3][4],int r,int c) {
	int temp = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == j) {
				temp = matrix[i][j];
			}
			matrix[i][j] /= temp;
		}
		toDiagonal(matrix,r,c,i);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d", matrix[i][j]);
		}
		printf("\n");
	}
}


int main() {
	int matrix[3][4] = { 1,1,1,6,1,2,4,3,1,3,9,2 };
	int r = 3, c = 4;
	gaussJordanElimination(matrix,r,c);

	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d", matrix[i][j]);
		}
		printf("\n");
	}*/
	return 0;

}