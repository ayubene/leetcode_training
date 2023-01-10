void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
	int flag_row0 = false;
	int m = matrixSize;
	int n = matrixColSize[0];
	int i = 0, j = 0;
	//printf("m01%d\n",matrix[0][1]);
	for (j = 0; j < n; j++) {
		if (matrix[0][j] == 0) {
			flag_row0 = true;
		}
	}
	for (i = 1; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	//printf("%d",flag_row0);
	for (i = 1; i < m; i++) {
		for (j = n - 1; j >= 0; j--) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}
	if (flag_row0) {
		for (j = 0; j < n; j++) {
			matrix[0][j] = 0;
		}
	}
}