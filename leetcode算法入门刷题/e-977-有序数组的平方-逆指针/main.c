#include<stdio.h>
#include<stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
	int p1 = 0, p2 = numsSize - 1;
	int* ret = malloc(sizeof(int) * numsSize);
	int mid = -1;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] < 0)mid++;
	}
	int cur;
	int index = numsSize - 1;
	while (p1 <= mid || p2 > mid) {
		if (p1 > mid) {
			cur = nums[p2--];
		}
		else if (p2 <= mid) {
			cur = nums[p1++];
		}
		else if (-nums[p1] > nums[p2]) {
			cur = nums[p1++];
		}
		else {
			cur = nums[p2--];
		}
		cur *= cur;
		ret[index--] = cur;
	}
	*returnSize = numsSize;
	return ret;
}

int main() {
	int nums[] = {-4,-1,0,3,10 };
	int numsSize = 5;
	int* returnSzie;
	int a = 10;
	returnSzie = &a;
	int* ret = sortedSquares(nums, numsSize, returnSzie);
	for (int i = 0; i < numsSize; i++) {
		printf("%d\n", ret[i]);
	}
}

/*
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
	int* ans = malloc(sizeof(int) * numsSize);
	*returnSize = numsSize;
	for (int i = 0, j = numsSize - 1, pos = numsSize - 1; i <= j;) {
		if (nums[i] * nums[i] > nums[j] * nums[j]) {
			ans[pos] = nums[i] * nums[i];
			++i;
		} else {
			ans[pos] = nums[j] * nums[j];
			--j;
		}
		--pos;
	}
	return ans;
}

*/