#include<stdio.h>
#include<stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
	int* sorted = malloc(sizeof(int) * numsSize);
	int p1 = -1, p2;
	for (int i = 0; i<numsSize; i++) {
		if (nums[i] < 0)p1++;
	}
	p2 = p1 + 1;
	int cur;
	int index = 0;
	while ((p1 >= 0 || p2 < numsSize)&&index<numsSize) {
		if (p1 == -1) {
			cur = nums[p2++]; 
		}
		else if (p2 == numsSize) {
			cur = nums[p1--];
		}
		else if (-nums[p1] < nums[p2]) {
			cur = nums[p1--];
		}
		else {
			cur = nums[p2++];
		}
		cur *= cur;
		sorted[index++] = cur;
	}
	*returnSize = numsSize;
	return sorted;
}

int main() {
	int nums[] = { -1 };
	int numsSize = 1;
	int* returnSzie;
	int a = 10;
	returnSzie = &a;
	int *ret = sortedSquares(nums, numsSize, returnSzie);
	for (int i = 0; i<numsSize; i++) {
		printf("%d\n", ret[i]);
	}
}
/*
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
	int negative = -1;
	for (int i = 0; i < numsSize; ++i) {
		if (nums[i] < 0) {
			negative = i;
		} else {
			break;
		}
	}

	int* ans = malloc(sizeof(int) * numsSize);
	*returnSize = 0;
	int i = negative, j = negative + 1;
	while (i >= 0 || j < numsSize) {
		if (i < 0) {
			ans[(*returnSize)++] = nums[j] * nums[j];
			++j;
		} else if (j == numsSize) {
			ans[(*returnSize)++] = nums[i] * nums[i];
			--i;
		} else if (nums[i] * nums[i] < nums[j] * nums[j]) {
			ans[(*returnSize)++] = nums[i] * nums[i];
			--i;
		} else {
			ans[(*returnSize)++] = nums[j] * nums[j];
			++j;
		}
	}

	return ans;
}

*/