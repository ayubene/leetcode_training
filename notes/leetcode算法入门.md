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
**练习时间：20230111**
## day06
### m-3-无重复字符的最长子串
* 因为这道题不只有字母，还有标点符号，空格等，因此使用128的char数组
* 看了别人的代码，我好像用的是哈希
```c
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int lengthOfLongestSubstring(char* s) {
	int ch[128] = { 0 };
	int start = 0, end = 0, ans = 0;
	int index = -1;
    
	for (int i = 0; i < strlen(s); i++) {
		index=s[i]-'\0';
		if (ch[index] != 0) {
			start = max(start, ch[index]);
			ch[index] = i + 1;
			ans = max(end - start + 1, ans);
		}
		else {
			ch[index] = i + 1;
			ans = max(end - start + 1, ans);
            //end+=1;
		}
        end+=1;
	}
	return ans;
}
```
* 看别人写的是这样的
  + 纯滑动窗口
  ```c
	int lengthOfLongestSubstring(char * s)
	{
		//类似于hash的思想
		//滑动窗口维护
		int left = 0;
		int right = 0;
		int max = 0;
		int i,j;
		int len = strlen(s);
		int haveSameChar = 0;
		for(i =0; i < len ; i++  )
		{
			if(left <= right)
			{   
				//检测是否出现重复
				//循环遍历整个数组 left -> right
				haveSameChar = 0;
				for(j = left; j < right ; j++)
				{
					if(s[j] == s[right])
					{
						haveSameChar = 1;
						break;
					}
				}
				if(haveSameChar)
				{
					//指向下一个
					left = j +1;
				}
			}
			//统计最大的间距
			max = max < (right - left + 1) ? (right - left + 1): max;
			right++;
		}
		return max;
	}

	作者：goodgoodday
	链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-u22kb/
	来源：力扣（LeetCode）
	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	```
  + 滑动+哈希
  ```c
	int lengthOfLongestSubstring(char* s)
	{
		//滑动窗口

		int indexLeft   = 0;
		int indexRight  = 0;
		int len = strlen(s);


		int hashMap[255] = { 0 };
		int maxCount = 0;
		while (indexRight < strlen(s))
		{
			if (hashMap[s[indexRight]] != 0)
			{
				//重复出现了
				if(hashMap[s[indexRight]] > indexLeft)
					indexLeft = hashMap[s[indexRight]];
				hashMap[s[indexRight]] = indexRight + 1;
			}
			else
			{
				hashMap[s[indexRight]] = indexRight + 1;
			}
			maxCount = fmax(maxCount, indexRight - indexLeft + 1);
			indexRight++;
		}
		return maxCount;
	}

	作者：goodgoodday
	链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-u22kb/
	来源：力扣（LeetCode）
	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	```
  + 滑动+数组哈希
  ```c
	int lengthOfLongestSubstring(char * s)
	{
		//类似于hash的思想
		//因为字符ASCII的最大值为127
		int hash[127] = {0};    
		//双指针思想 维护2个窗口
		int left = 0;
		int right = 0;
		int max = 0;

		//循环遍历整个数组
		while(s[right])
		{
			if(hash[s[right]] && left < hash[s[right]])
			{   
				//右侧重复出现
				//左指针向前移动
				left = hash[s[right]];  
			}
			//记录当前
			//保存如果出现重复原始时，下标指向的位置
			hash[s[right]] = right + 1;
			max = max < (right - left + 1) ? (right - left + 1): max;
			right++;//右指针每次都要加一。
		}
		return max;
	}

	作者：goodgoodday
	链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-u22kb/
	来源：力扣（LeetCode）
	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	```
### m-567-字符串的排列
* 这道题打了好久好久好久，但好像稍微搞清楚了一点具体应该怎么解
* 不过我的方法很慢，效率不高

```c
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool checkInclusion(char* s1, char* s2) {
	int ch1[26] = { 0 };
	int ch2[26] = { 0 };
	if (strlen(s1) > strlen(s2)) {
		return false;
	}
	for (int i = 0; i < strlen(s1); i++) {
		ch1[s1[i] - 'a'] += 1;
		ch2[s2[i] - 'a'] += 1;
	}
	int start = 0, end = strlen(s1) - 1;
	int flag = 1;
	for (int j = strlen(s1) - 1; j < strlen(s2); j++) {
		//flag = 0;
		for (int k = 0; k < strlen(s1); k++) {
			//printf("%3d%3d",s1[k] - 'a',s2[start+k] - 'a');
			//int tmpstart=start;
			if (ch1[s1[k] - 'a'] == ch2[s1[k] - 'a']) {
				///printf("aaa");
				flag = 1;
			}
			else {
				flag = 0; break;
			}
		}
		printf("bbb");
		if (flag) {
			return true;
		}
		//end = j;
		end++;
		ch2[s2[start] - 'a'] -= 1;
		if (s2[end] != '\0') {
			ch2[s2[end] - 'a'] += 1;
		}
		start++;
	}
	return flag;
}
int main() {
	char* s1 = { "ab" };
	char* s2 = { "eidboaoo" };
	bool t = checkInclusion(s1, s2);
}
```
* 官方解法1

```c
bool equals(int* cnt1, int* cnt2) {
    for (int i = 0; i < 26; i++) {
        if (cnt1[i] != cnt2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(char* s1, char* s2) {
    int n = strlen(s1), m = strlen(s2);
    if (n > m) {
        return false;
    }
    int cnt1[26], cnt2[26];
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 0; i < n; ++i) {
        ++cnt1[s1[i] - 'a'];
        ++cnt2[s2[i] - 'a'];
    }
    if (equals(cnt1, cnt2)) {
        return true;
    }
    for (int i = n; i < m; ++i) {
        ++cnt2[s2[i] - 'a'];
        --cnt2[s2[i - n] - 'a'];
        if (equals(cnt1, cnt2)) {
            return true;
        }
    }
    return false;
}

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/permutation-in-string/solution/zi-fu-chuan-de-pai-lie-by-leetcode-solut-7k7u/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
* 官方优化解法

```c
bool checkInclusion(char* s1, char* s2) {
    int n = strlen(s1), m = strlen(s2);
    if (n > m) {
        return false;
    }
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
        --cnt[s1[i] - 'a'];
        ++cnt[s2[i] - 'a'];
    }
    int diff = 0;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] != 0) {
            ++diff;
        }
    }
    if (diff == 0) {
        return true;
    }
    for (int i = n; i < m; ++i) {
        int x = s2[i] - 'a', y = s2[i - n] - 'a';
        if (x == y) {
            continue;
        }
        if (cnt[x] == 0) {
            ++diff;
        }
        ++cnt[x];
        if (cnt[x] == 0) {
            --diff;
        }
        if (cnt[y] == 0) {
            ++diff;
        }
        --cnt[y];
        if (cnt[y] == 0) {
            --diff;
        }
        if (diff == 0) {
            return true;
        }
    }
    return false;
}

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/permutation-in-string/solution/zi-fu-chuan-de-pai-lie-by-leetcode-solut-7k7u/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
* 官方双指针
```c
bool checkInclusion(char* s1, char* s2) {
    int n = strlen(s1), m = strlen(s2);
    if (n > m) {
        return false;
    }
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
        --cnt[s1[i] - 'a'];
    }
    int left = 0;
    for (int right = 0; right < m; ++right) {
        int x = s2[right] - 'a';
        ++cnt[x];
        while (cnt[x] > 0) {
            --cnt[s2[left] - 'a'];
            ++left;
        }
        if (right - left + 1 == n) {
            return true;
        }
    }
    return false;
}

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/permutation-in-string/solution/zi-fu-chuan-de-pai-lie-by-leetcode-solut-7k7u/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```
