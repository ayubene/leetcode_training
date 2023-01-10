void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void moveZeroes(int* nums, int numsSize) {
	//iΪ��ָ�룬ָ����ȷ�����е�β����jΪ��ָ�룬ָ��δȷ�����е�ͷ��
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

���ߣ�LeetCode-Solution
���ӣ�https://leetcode.cn/problems/move-zeroes/solution/yi-dong-ling-by-leetcode-solution/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/