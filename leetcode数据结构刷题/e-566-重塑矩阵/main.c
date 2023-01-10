/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
	if (r * c != matSize * matColSize[0]) {
		*returnSize = matSize;
		*returnColumnSizes = matColSize;
		return mat;
	}
	int** ret = malloc(sizeof(int*) * r);
	
	//ret[0][0] = 1;
	int m = 0, n = 0;

	*returnSize = r;
	*returnColumnSizes = malloc(sizeof(int) * r);
	for (int k = 0; k < r; k++) {
		ret[k] = malloc(sizeof(int) * c);
		(*returnColumnSizes)[k] = c;
	}
	for (int i = 0; i < matSize; i++) {
		for (int j = 0; j < matColSize[0]; j++) {
			m = (i * matColSize[0] + j) / c;
			n = (i * matColSize[0] + j) % c;
			ret[m][n] = mat[i][j];
		}
	}
	/*这样更好
	for (int x = 0; x < m * n; ++x) {
        ans[x / c][x % c] = nums[x / n][x % n];
    }

	作者：LeetCode-Solution
	链接：https://leetcode.cn/problems/reshape-the-matrix/solution/zhong-su-ju-zhen-by-leetcode-solution-gt0g/
	来源：力扣（LeetCode）
	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	*/
	//int retColSize[2][1] = { {r},{c} };
	return ret;
}

int main() {
	//int mat[2][2] = { {1,2},{3,4} };
	int** mat = malloc(sizeof(int*) * 1);
	for (int k = 0; k < 1; k++) {
		mat[k] = (int*)malloc(sizeof(int) * 4);
	}
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[0][2] = 3;
	mat[0][3] = 4;
	int matSize = 1;
	int *matColSize=malloc(sizeof(int) * 2);
	matColSize[0] = 4;
	matColSize[1] = 4;
	int target = 11;
	int a = 0;
	int b[] = { 0 };
	int r =2, c =2;
	//int** returnColumnSizes;
	int* returnSize;
	returnSize = &a;
	int** returnColumnSizes = malloc(sizeof(int*) * 2);
	for (int k = 0; k < 2; k++) {
		returnColumnSizes[k] = (int*)malloc(sizeof(int) * 2);
	}
	 
	 
	int** ret = matrixReshape(mat, matSize, matColSize, r,c,returnSize, returnColumnSizes);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d\n", ret[i][j]);
		}
	}
}