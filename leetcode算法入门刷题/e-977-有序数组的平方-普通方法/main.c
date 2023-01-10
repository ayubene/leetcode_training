/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdlib.h>
int cmp(int* a, int* b) {
	return *a - *b;
}
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
	for (int i = 0; i < numsSize; i++) {
		nums[i] *= nums[i];
	}
	qsort(nums, numsSize, sizeof(int), cmp);
	*returnSize = numsSize;
	return nums;
}