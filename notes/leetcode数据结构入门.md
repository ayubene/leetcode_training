**练习时间：20230102**
## day02
### e-1-两数之和
* 这块有两种方法,一种是暴力解法,另一种是哈希解法
  + 我自己写的暴力解法
  ```c
    /**
    * Note: The returned array must be malloced, assume caller calls free().
    */
    //普通暴力解法（自己写的）
    //实在想不通这里的returnSize有什么用
    int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
        int sub;
        int *index;
        index = (int*)malloc(sizeof(int) * 2);
        for (int i = 0; i < numsSize; i++)
        {
            sub = target - nums[i];
            index[0] = i;
            for (int j = i + 1; j < numsSize; j++)
            {
                if (sub == nums[j])
                {
                    index[1] = j;
                    *returnSize = 2;
                    return index;
                }
            }
        }
        *returnSize = 0;
        return NULL;
    }
  ```
  + 哈希解法
  ```c
    #include"uthash.h"
    #include<stdio.h>
    #include<stdlib.h>
    #include <stdbool.h>

    // 使用哈希表
    //key存内容，val存下标
    struct hashTable {
        int key;
        int val;
        UT_hash_handle hh; /* makes this structure hashable */
    };

    //使用这个哈希表存遍历过的，没有找到与target-nums[i]相等的key和val
    struct hashTable* hashtable;

    //find函数用于寻找target-nums[i]是否存在于当前哈希表中，如果存在，赋给tmp；否则tmp==NULL
    struct hashTable* find(int ikey) {
        struct hashTable* tmp;
        HASH_FIND_INT(hashtable, &ikey, tmp);/* id already in the hash? */ /*重复性检查，当把两个相同key值的结构体添加到哈希表中时会报错*/
        return tmp;
    }

    //insert函数用于将新的哈希值插入哈希表中
    void insert(int ikey, int ival) {
        struct hashTable* it = find(ikey);
        if (it == NULL) {
            struct hashTable* tmp = malloc(sizeof(struct hashTable));
            tmp->key = ikey;
            tmp->val = ival;
            HASH_ADD_INT(hashtable, key, tmp);
        }
        //如果所给数组中有相同的key值，因为用哪个都可以，所以这里换一下,但是没有这个else也可以
        else {
            it->val = ival;
        }
    }

    int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
        hashtable = NULL;
        for (int i = 0; i < numsSize; i++) {
            struct hashTable* it = find(target - nums[i]);
            //如果找到key值等于target - nums[i]的，输出当前i值和找到的对应key的val即可
            if (it != NULL) {
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = it->val; ret[1] = i;
                *returnSize = 2;
                return ret;
            }
            //如果没有找到，就插入哈希表即可
            insert(nums[i], i);
        }
        *returnSize = 0;
        return NULL;
    }

    int main() {
        int nums[] = { 1,3,3,2,3,8 };
        int numsSize = 6;
        int target = 11;
        int a = 0;
        int* returnSize;
        returnSize = &a;
        int* ret = twoSum(nums, numsSize, target, returnSize);
        printf("[%d,%d]",ret[0],ret[1]);
    }

    ```

* 这里搞清楚了一点指针的知识
  + 暴力解法中一直不懂*returnSize有什么用，为什么就可以直接赋值为2，看了一下指针相关知识，了解了个大概，可以看看这个代码
  ```c
    #include <stdio.h>
    int test(int* ip)
    {
        *ip = 2;
    }
    int main()
    {
        int  var = 20;   /* 实际变量的声明 */
        int* ip;        /* 指针变量的声明 */

        ip = &var;  /* 在指针变量中存储 var 的地址 */

        printf("var 变量的地址: %p\n", &var);

        /* 在指针变量中存储的地址 */
        printf("ip 变量存储的地址: %p\n", ip);

        /* 使用指针访问值 */
        printf("*ip 变量的值: %d\n", *ip);

        test(ip);

        return 0;
    }
  ```
  + 最后*ip的值为2，连带着修改了var的值变为2
* 关于哈希表的使用
  + 这里是第二次打哈希表相关代码了，比之前好了很多，也差不多理解了整个代码。具体的解释在代码上都注释了

### e-88-合并两个有序数组
#### 普通方法
* 合并两个数组然后快排
#### 双指针
* 我的错误在于，看了题解说用指针，我就用了int *p，对指针的理解还是很狭窄。标准答案在代码最下面，可以再看看
```c
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int* p1 = nums1;
	int* p2 = nums2;
	int* nums = malloc(sizeof(int) * (m + n));
	int mm = m, nn = n;
	for (int i = 0; i < m + n; i++) {
		if (mm == 0) {
			for (int j = i; j < m+n; j++) {
				nums[j] = nums2[j-m];
			}
			for (int i = 0; i != m + n; ++i) {
				nums1[i] = nums[i];
			}
			return;
		}
		if (nn == 0) {
			for (int j = i; j < m + n; j++) {
				nums[j] = nums1[j - n];
			}
			for (int i = 0; i != m + n; ++i) {
				nums1[i] = nums[i];
			}
			return;
		}
		if (*p1 < *p2) {
			nums[i] = *p1;
			p1++;
			mm--;
		}
		else {
			nums[i] = *p2;
			p2++;
			nn--;
		}
	}
	for (int i = 0; i != m + n; ++i) {
		nums1[i] = nums[i];
	}
}

int main() {
	int nums1[] = { 2,0 };
	int nums2[] = { 1 };
	int m = 1, n = 1;
	int numsSize = 9;
	merge(nums1, 2, 1, nums2, 1,1);
	for (int i = 0; i < m + n; i++)
	{
		printf("%3d\n", nums1[i]);
	}
	
}

/*
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int p1 = 0, p2 = 0;
	int sorted[m + n];
	int cur;
	while (p1 < m || p2 < n) {
		if (p1 == m) {
			cur = nums2[p2++];
		} else if (p2 == n) {
			cur = nums1[p1++];
		} else if (nums1[p1] < nums2[p2]) {
			cur = nums1[p1++];
		} else {
			cur = nums2[p2++];
		}
		sorted[p1 + p2 - 1] = cur;
	}
	for (int i = 0; i != m + n; ++i) {
		nums1[i] = sorted[i];
	}
}

*/
```
#### 逆向双指针
* 在这里发现我对a--和--a掌握不够，
```
a=2;
x[a--]即x[2]，之后a=1
```
* 最下面是标准答案
```c
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int p1 = m-1, p2 = n-1;
	int index = m + n - 1;
	int cur;
	while ((p1 != -1 || p2 != -1)&&index!=-1) {
		if (p1 == -1) {
			cur = nums2[p2];
			p2--;
		}
		else if (p2 == -1) {
			cur = nums1[p1];
			p1--;
		}
		else if (nums1[p1] > nums2[p2]) {
			cur = nums1[p1];
			p1--;
		}
		else {
			cur = nums2[p2];
			p2--;
		}
		nums1[index] = cur;
		index--;
	}

}

int main() {
	int nums1[] = { 1, 2, 3, 0, 0, 0 };
	int nums2[] = { 2, 5, 6 };
	int m = 3, n = 3;
	int numsSize = 9;
	merge(nums1, 6, 3, nums2, 3 , 3);
	for (int i = 0; i < m + n; i++)
	{
		printf("%3d\n", nums1[i]);
	}

} 

/*
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int p1 = m - 1, p2 = n - 1;
	int tail = m + n - 1;
	int cur;
	while (p1 >= 0 || p2 >= 0) {
		if (p1 == -1) {
			cur = nums2[p2--];
		} else if (p2 == -1) {
			cur = nums1[p1--];
		} else if (nums1[p1] > nums2[p2]) {
			cur = nums1[p1--];
		} else {
			cur = nums2[p2--];
		}
		nums1[tail--] = cur;
	}
}
*/
```
## day04

#### e-566-重塑矩阵
* 卡在这里很久 因为对于题目的 int* matColSize 到底是什么意思不理解，最开始觉得 matColSize[0] = matColSize[1] = 列数，所以写的时候都用了 matColSize[1]，一直过不去，之后改成matColSize[0]一下子就过了。不过还是不懂到底是什么意思，给个行列不就行了吗，我是这样想的。
* 想了一下，稍微有一点点理解了
  ```
  m == mat.length
  n == mat[i].length
  ```
  所以matColSize[i]就是第i行有几个元素。虽然还是不知道为什么要这样，我想有可能是有的行没有元素或者元素较少？
* 写一下矩阵的初始化方法，包括普通方法和malloc方法

```c
//按行分段赋值
int a[5][3]={ {80,75,92}, {61,65,71}, {59,63,70}, {85,87,90}, {76,77,85} };
//按行连续赋值
int a[5][3]={80, 75, 92, 61, 65, 71, 59, 63, 70, 85, 87, 90, 76, 77, 85};
//可以只对部分元素赋值，未赋值的元素自动取“零”值。例如：
int a[3][3] = {{1}, {2}, {3}};
//如果对全部元素赋值，那么第一维的长度可以不给出。例如：
int a[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//malloc
int** mat = malloc(sizeof(int*) * row);
	for (int k = 0; k < row; k++) {
		mat[k] = (int*)malloc(sizeof(int) * column);
	}
```
```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
	if (r * c != matSize * matColSize[0]) {
		*returnSize = matSize;
		*returnColumnSizes = matColSize;
		return mat;
	}
	int** ret = malloc(sizeof(int*) * r);
	
	//ret[0][0] = 1;
	int m = 0, n = 0;

	*returnSize = r;
	*returnColumnSizes = malloc(sizeof(int) * r);
	for (int k = 0; k < r; k++) {
		ret[k] = malloc(sizeof(int) * c);
		(*returnColumnSizes)[k] = c;
	}
	for (int i = 0; i < matSize; i++) {
		for (int j = 0; j < matColSize[0]; j++) {
			m = (i * matColSize[0] + j) / c;
			n = (i * matColSize[0] + j) % c;
			ret[m][n] = mat[i][j];
		}
	}
	/*这样更好
	for (int x = 0; x < m * n; ++x) {
        ans[x / c][x % c] = nums[x / n][x % n];
    }

	作者：LeetCode-Solution
	链接：https://leetcode.cn/problems/reshape-the-matrix/solution/zhong-su-ju-zhen-by-leetcode-solution-gt0g/
	来源：力扣（LeetCode）
	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
	*/
	//int retColSize[2][1] = { {r},{c} };
	return ret;
}

int main() {
	//int mat[2][2] = { {1,2},{3,4} };
	int** mat = malloc(sizeof(int*) * 1);
	for (int k = 0; k < 1; k++) {
		mat[k] = (int*)malloc(sizeof(int) * 4);
	}
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[0][2] = 3;
	mat[0][3] = 4;
	int matSize = 1;
	int *matColSize=malloc(sizeof(int) * 2);
	matColSize[0] = 4;
	matColSize[1] = 4;
	int target = 11;
	int a = 0;
	int b[] = { 0 };
	int r =2, c =2;
	//int** returnColumnSizes;
	int* returnSize;
	returnSize = &a;
	int** returnColumnSizes = malloc(sizeof(int*) * 2);
	for (int k = 0; k < 2; k++) {
		returnColumnSizes[k] = (int*)malloc(sizeof(int) * 2);
	}
	 
	 
	int** ret = matrixReshape(mat, matSize, matColSize, r,c,returnSize, returnColumnSizes);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			printf("%d\n", ret[i][j]);
		}
	}
}
```

**练习时间：20230110**
## day05
### m-36-有效的数独
* 这题不算难,需要用到哈希表,但是我有点思维固化,一想到哈希表就去用那个uhash.h，但是这个用数组可以很简单地实现

### e-876-链表的中间结点
* 这里有一个思想，快慢指针。因为不知道链表长度，用一个指针每次走两步，一个指针每次走一步，这样走两步的走到头以后，走一步的刚好在中间。