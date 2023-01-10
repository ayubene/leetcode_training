void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void moveZeroes(int* nums, int numsSize) {
	//i为左指针，指向已确定序列的尾部，j为右指针，指向未确定序列的头部
	int i = 0, j = 0;
	while (j < numsSize) {
		if (nums[j] != 0) {
			swap(&nums[i], &nums[j]);
			i++;
			j++;
		}
		else {
			j++;
		}
	}
	for (int k = i + 1; k < numsSize; k++) {
		nums[k] = 0;
	}
}

/*
void swap(int *a, int *b) {
	int t = *a;
	*a = *b, *b = t;
}

void moveZeroes(int *nums, int numsSize) {
	int left = 0, right = 0;
	while (right < numsSize) {
		if (nums[right]) {
			swap(nums + left, nums + right);
			left++;
		}
		right++;
	}
}

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/move-zeroes/solution/yi-dong-ling-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/