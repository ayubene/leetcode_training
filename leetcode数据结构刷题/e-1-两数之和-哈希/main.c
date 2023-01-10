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
