//头文件来自开源的第三方uthash
//官网链接https://troydhanson.github.io/uthash/
//可阅读这篇了解uthash相关函数https://zhuanlan.zhihu.com/p/340692819
#include"uthash.h"
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
// 使用哈希表
struct hashTable {
    int key;
    UT_hash_handle hh; /* makes this structure hashable */
};

bool containsDuplicate(int* nums, int numsSize) {
    struct hashTable* set = NULL;  /* important! initialize to NULL */
    for (int i = 0; i < numsSize; i++)
    {
        struct hashTable* tmp;
        HASH_FIND_INT(set, nums + i, tmp);/* id already in the hash? */ /*重复性检查，当把两个相同key值的结构体添加到哈希表中时会报错*/
        if (tmp == NULL)
        {
            tmp = malloc(sizeof(struct hashTable));
            tmp->key = nums[i];
            HASH_ADD_INT(set, key, tmp);/*添加int类型的键值。第一个参数是哈希表，第二个参数是键字段的名称，最后一个参数是指向要添加的结构的指针。*/
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main() {
    int nums[] = { 1,3,2,4 };
    int a=containsDuplicate(nums, 4);
    if (a)
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }
}