#include<stdio.h>

int search(int* nums, int numsSize, int target) {
	int left, right;
	left = 0;
	right = numsSize - 1;
	int temp = (left + right) / 2;
	while (left<right-1)
	{
		if (nums[temp] == target)
		{
			return temp;
		}
		else if (nums[temp] > target)
		{
			right = temp;
			temp = (left + right) / 2;
		}
		else
		{
			left = temp;
			temp = (left + right) / 2;
		}
	}
	if (left == right || left == right - 1)
	{
		if (target == nums[left]) return left;
		else if (target == nums[right]) return right;
		//else return -1;
	}
	/*if (left == right)
	{
		return -1;
	}*/
	return -1;
}
int main() {
	int nums[] = { -1, 0, 3, 5, 9, 12 };
	int numsSize = 6;
	int target = 9;
	int ans = search(nums, numsSize, target);
	printf("%d\n", ans);
}