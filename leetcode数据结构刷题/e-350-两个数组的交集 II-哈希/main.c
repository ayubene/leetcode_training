/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include"uthash.h"
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

 // 使用哈希表
 //key存内容，num存该数字在较短数组中的个数
struct hashTable {
	int key;
	int num;
	UT_hash_handle hh; /* makes this structure hashable */
};

struct hashTable* hashtable;

//find1函数用于寻找shorter[i]是否存在于当前哈希表中，如果存在，num++,赋给tmp；否则tmp==NULL
struct hashTable* find1(int ikey) {
	struct hashTable* tmp;
	HASH_FIND_INT(hashtable, &ikey, tmp);/* id already in the hash? */ /*重复性检查，当把两个相同key值的结构体添加到哈希表中时会报错*/
	
	return tmp;
}
//find2函数用于寻找longer[i]是否存在于当前哈希表中，如果存在，num--,赋给tmp；否则tmp==NULL
struct hashTable* find2(int ikey) {
	struct hashTable* tmp;
	HASH_FIND_INT(hashtable, &ikey, tmp);/* id already in the hash? */ /*重复性检查，当把两个相同key值的结构体添加到哈希表中时会报错*/
	
	return tmp;
}

void check(int ikey) {
	struct hashTable* t = find2(ikey);
	if (t != NULL) {
		printf("key=%d\n", t->key);
		printf("num=%d\n", t->num);
	}
}

bool isRepeated(int ikey) {
	struct hashTable* it = find2(ikey);
	if (it == NULL||it->num<=0) {
		return false;
	}
	else {
		it->num -= 1;
		//check(ikey);
		return true;
	}
}

//insert函数用于将新的哈希值插入哈希表中
void insert(int ikey) {
	struct hashTable* it = find1(ikey);
	if (it == NULL) {
		struct hashTable* tmp = malloc(sizeof(struct hashTable));
		tmp->key = ikey;
		tmp->num = 1;
		HASH_ADD_INT(hashtable, key, tmp);
	}
	//如果所给数组中有相同的key值，num++
	else {
		it->num += 1;
	}
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
	int* shorter;
	int* longer;
	int shorterSize, longerSize;
	*returnSize = 0;
	if (nums1Size < nums2Size) {
		shorter = nums1; shorterSize = nums1Size;
		longer = nums2; longerSize = nums2Size;
	}
	else {
		shorter = nums2; shorterSize = nums2Size;
		longer = nums1; longerSize = nums1Size;
	}
	int* ret = malloc(sizeof(int) * shorterSize);
	hashtable = NULL;
	for (int i = 0; i < shorterSize; i++) {
		insert(shorter[i]);
	}
	int flag = -1;
	int index = 0;
	for (int j = 0; j < longerSize; j++) {
		flag = isRepeated(longer[j]);
		if (flag == 1) {
			ret[index++] = longer[j];
		}
	}
	*returnSize = index;
	return ret;
}

int main() {
	int nums1[] = { 54, 93, 21, 73, 84, 60, 18, 62, 59, 89, 83, 89, 25, 39, 41, 55, 78, 27, 65, 82, 94, 61, 12, 38, 76, 5, 35, 6, 51, 48, 61, 0, 47, 60, 84, 9, 13, 28, 38, 21, 55, 37, 4, 67, 64, 86, 45, 33, 41};
	int nums2[] = { 17, 17, 87, 98, 18, 53, 2, 69, 74, 73, 20, 85, 59, 89, 84, 91, 84, 34, 44, 48, 20, 42, 68, 84, 8, 54, 66, 62, 69, 52, 67, 27, 87, 49, 92, 14, 92, 53, 22, 90, 60, 14, 8, 71, 0, 61, 94, 1, 22, 84, 10, 55, 55, 60, 98, 76, 27, 35, 84, 28, 4, 2, 9, 44, 86, 12, 17, 89, 35, 68, 17, 41, 21, 65, 59, 86, 42, 53, 0, 33, 80, 20 };
	int nums1Size = 49, nums2Size = 82;
	int target = 11;
	int a = 0;
	int* returnSize;
	returnSize = &a;
	int* ret = intersect(nums1, nums1Size, nums2, nums2Size,returnSize);
	//printf("[%d,%d]", ret[0], ret[1]);
	for (int i = 0; i < nums1Size; i++) {
		rintf("%d\n", ret[i]);
	}
}