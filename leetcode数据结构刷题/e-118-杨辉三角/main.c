/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
	int** ret;
	*returnSize = numRows;
	*returnColumnSizes = malloc(sizeof(int) * numRows);
	ret = malloc(sizeof(int*) * numRows);
	for (int k = 0; k < numRows; k++) {
		ret[k] = malloc(sizeof(int) * (k + 1));
		(*returnColumnSizes)[k] = k + 1;
	}
	ret[0][0] = 1;
	for (int i = 1; i < numRows; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)ret[i][j] = 1;
			else ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
		}
	}
	return ret;
}