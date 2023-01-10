/*题解在这里https://leetcode.cn/problems/maximum-subarray/solution/hua-jie-suan-fa-53-zui-da-zi-xu-he-by-guanpengchn/
本题使用了动态规划求解*/
#include<stdio.h>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize) {
	int sum = nums[0];
	int ans = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		if (sum <= 0)
		{
			sum = nums[i];
			ans = max(ans, sum);
		}
		else
		{
			sum += nums[i];
			ans = max(ans, sum);
		}
	}
	return ans;
}

int main() {
	int nums[] = { -2,1,-3,4,-1,2,1,-5,4 };
	int numsSize = 9;
	int ans = maxSubArray(nums, numsSize);
	printf("%d\n", ans);
}