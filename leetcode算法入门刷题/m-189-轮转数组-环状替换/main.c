#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap2(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb, * pb = tmp;
}
//求最大公约数
int hcf(int n1, int n2)
{
	if (n2 != 0)
		return hcf(n2, n1 % n2);
	else
		return n1;
}
void rotate(int* nums, int numsSize, int k) {
	
	int t = -1;
	int gcd = hcf(k, numsSize);
	int b = gcd;
	while (gcd) {
		t++;
		int temp = nums[t];
		int a = t;
		int i = 0;
		for (i = 0; i < numsSize / b; i++) {
			a = (a + k) % numsSize;
			swap2(&temp, &nums[a]);
		}
		gcd--;
	}
}


int main() {
	int nums[] = { -1, -100, 3, 99 };
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

/*
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b, *b = t;
}

void rotate(int* nums, int numsSize, int k) {
	k = k % numsSize;
	int count = gcd(k, numsSize);
	for (int start = 0; start < count; ++start) {
		int current = start;
		int prev = nums[start];
		do {
			int next = (current + k) % numsSize;
			swap(&nums[next], &prev);
			current = next;
		} while (start != current);
	}
}

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/rotate-array/solution/xuan-zhuan-shu-zu-by-leetcode-solution-nipk/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/