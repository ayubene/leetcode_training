#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void reverse(int* nums, int start, int end) {
	while (start < end) {
		swap(&nums[start], &nums[end]);
		start++;
		end--;
	}
}

void rotate(int* nums, int numsSize, int k) {
	reverse(nums, 0, numsSize - 1);
	int t = k % numsSize;
	reverse(nums, 0, t - 1);
	reverse(nums, t, numsSize-1);
}


int main() {
	int nums[] = { 1,2,3,4 };
	int numsSize = 4;
	int k = 2;
	int* returnSzie;
	int a = 10;
	returnSzie = &a;
	rotate(nums, numsSize, k);
	for (int i = 0; i < numsSize; i++) {
		printf("%d\n", nums[i]);
	}
}
