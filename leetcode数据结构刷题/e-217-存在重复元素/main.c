//ͷ�ļ����Կ�Դ�ĵ�����uthash
//��������https://troydhanson.github.io/uthash/
//���Ķ���ƪ�˽�uthash��غ���https://zhuanlan.zhihu.com/p/340692819
#include"uthash.h"
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
// ʹ�ù�ϣ��
struct hashTable {
    int key;
    UT_hash_handle hh; /* makes this structure hashable */
};

bool containsDuplicate(int* nums, int numsSize) {
    struct hashTable* set = NULL;  /* important! initialize to NULL */
    for (int i = 0; i < numsSize; i++)
    {
        struct hashTable* tmp;
        HASH_FIND_INT(set, nums + i, tmp);/* id already in the hash? */ /*�ظ��Լ�飬����������ͬkeyֵ�Ľṹ����ӵ���ϣ����ʱ�ᱨ��*/
        if (tmp == NULL)
        {
            tmp = malloc(sizeof(struct hashTable));
            tmp->key = nums[i];
            HASH_ADD_INT(set, key, tmp);/*���int���͵ļ�ֵ����һ�������ǹ�ϣ���ڶ��������Ǽ��ֶε����ƣ����һ��������ָ��Ҫ��ӵĽṹ��ָ�롣*/
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