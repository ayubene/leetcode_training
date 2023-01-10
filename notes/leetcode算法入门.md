**练习时间：20230101**
## day01
### e-704-二分查找
#### 关于mid = left + (right - left) / 2 和 mid = (left + right)/2
* (left + right)/2有可能会溢出，如果两个值是 ‘int类型的最大值’ 和 ‘int类型的最大值减一’ 两个值相加就溢出了 ，但是用 left + (right - left) /2求均值 不会溢出
* 我写的代码要复杂许多，之后还要再练习

## day02
### e-977-有序数组的平方
* 本质是两个已经排序的数组合并为一个排序的数组
#### 普通方法
* 使用快排即可
```c
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
```
#### 双指针
```c
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
```
#### 逆向双指针
```c
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
```
### m-189-轮转数组
#### 普通方法
```c
void rotate(int* nums, int numsSize, int k) {
	int* ret = malloc(sizeof(int) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		ret[(i + k) % numsSize] = nums[i];
	}
	for (int j = 0; j < numsSize; j++) {
		nums[j] = ret[j];
	}
}
```
#### 环状替换
* 这里必须提的有：
  + 关于C语言如何通过形参改变实参，并且如何使用的问题
  ```c
    //举例
    void swap(int* a, int* b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
  ```
  如果使用的是int类型，则使用时swap(a,b)即可，而若为int数组里的项，则需要使用swap(&a,&b)。暂时不明白为什么。
  + 求最大公约数的几种方法
  ```c
    int hcf(int n1, int n2)
    {
        if (n2 != 0)
            return hcf(n2, n1 % n2);
        else
            return n1;
    }   
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
  ```
```c
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
```
#### 数组替换
* 这个方法简单又方便
```c
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

```
## day03
#### e-344-反转字符串
* 在练习过程中,发现很多时候用数组除了a[i]这种，可以用a+i这种。在几道题的标准答案里面看到过了

**练习时间：20230110**
## day05
### m-19-删除链表的倒数第 N 个结点
* 可以用双指针或者栈
* 双指针方法不太难，但是因为要删除，所以必须存下要删除的前一个结点。被这里困了很久，最后标准答案是给链表头结点前面又加了一个结点，很简单就完成了，如下
  ```c
	struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
		struct ListNode* dummy = malloc(sizeof(struct ListNode));
		dummy->val = 0, dummy->next = head;
		struct ListNode* first = head;
		struct ListNode* second = dummy;
		for (int i = 0; i < n; ++i) {
			first = first->next;
		}
		while (first) {
			first = first->next;
			second = second->next;
		}
		second->next = second->next->next;
		struct ListNode* ans = dummy->next;
		free(dummy);
		return ans;
	}

	作者：LeetCode-Solution
	链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/
	来源：力扣（LeetCode）
	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	```
* 栈的标准答案也写在这里
  ```c
	struct Stack {
		struct ListNode* val;
		struct Stack* next;
	};

	struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
		struct ListNode* dummy = malloc(sizeof(struct ListNode));
		dummy->val = 0, dummy->next = head;
		struct Stack* stk = NULL;
		struct ListNode* cur = dummy;
		while (cur) {
			struct Stack* tmp = malloc(sizeof(struct Stack));
			tmp->val = cur, tmp->next = stk;
			stk = tmp;
			cur = cur->next;
		}
		for (int i = 0; i < n; ++i) {
			struct Stack* tmp = stk->next;
			free(stk);
			stk = tmp;
		}
		struct ListNode* prev = stk->val;
		prev->next = prev->next->next;
		struct ListNode* ans = dummy->next;
		free(dummy);
		return ans;
	}

	作者：LeetCode-Solution
	链接：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/
	来源：力扣（LeetCode）
	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	```