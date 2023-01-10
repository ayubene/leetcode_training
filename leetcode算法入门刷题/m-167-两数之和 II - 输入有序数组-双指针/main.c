/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	int left = 0, right = numbersSize-1;
	*returnSize = 2;
	int* index = malloc(sizeof(int) * 2);
	while (left < right) {
		if ((numbers[left] + numbers[right]) < target) {
			left++;
		}
		else if ((numbers[left] + numbers[right]) > target){
			right--;
		}
		else {
			index[0] = left+1; index[1] = right+1;
			return index;
		}
	}
	index[0] = -1; index[1] = -1;
	return index;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	//int* ret = (int*)malloc(sizeof(int) * 2);
	//*returnSize = 2;

	int low = 0, high = numbersSize - 1;
	while (low < high) {
		int sum = numbers[low] + numbers[high];
		if (sum == target) {
			ret[0] = low + 1, ret[1] = high + 1;
			return ret;
		}
		else if (sum < target) {
			++low;
		}
		else {
			--high;
		}
	}
	ret[0] = -1, ret[1] = -1;
	return ret;
}

作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/solution/liang-shu-zhi-he-ii-shu-ru-you-xu-shu-zu-by-leet-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main() {
	int numbers[] = { 2,7,11,15 };
	int numbersSize = 4;
	int target = 9;
	int* t = malloc(sizeof(int) * 2);
	int* returnSzie;
	int a = 10;
	returnSzie = &a;
	t=twoSum(numbers, numbersSize, target, returnSzie);
	for (int i = 0; i < 2; i++) {
		printf("%d\n", t[i]);
	}
}