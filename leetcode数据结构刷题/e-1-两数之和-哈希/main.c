#include"uthash.h"
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

// ʹ�ù�ϣ��
//key�����ݣ�val���±�
struct hashTable {
    int key;
    int val;
    UT_hash_handle hh; /* makes this structure hashable */
};

//ʹ�������ϣ���������ģ�û���ҵ���target-nums[i]��ȵ�key��val
struct hashTable* hashtable;

//find��������Ѱ��target-nums[i]�Ƿ�����ڵ�ǰ��ϣ���У�������ڣ�����tmp������tmp==NULL
struct hashTable* find(int ikey) {
    struct hashTable* tmp;
    HASH_FIND_INT(hashtable, &ikey, tmp);/* id already in the hash? */ /*�ظ��Լ�飬����������ͬkeyֵ�Ľṹ����ӵ���ϣ����ʱ�ᱨ��*/
    return tmp;
}

//insert�������ڽ��µĹ�ϣֵ�����ϣ����
void insert(int ikey, int ival) {
    struct hashTable* it = find(ikey);
    if (it == NULL) {
        struct hashTable* tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey;
        tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);
    }
    //�����������������ͬ��keyֵ����Ϊ���ĸ������ԣ��������ﻻһ��,����û�����elseҲ����
    else {
        it->val = ival;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++) {
        struct hashTable* it = find(target - nums[i]);
        //����ҵ�keyֵ����target - nums[i]�ģ������ǰiֵ���ҵ��Ķ�Ӧkey��val����
        if (it != NULL) {
            int* ret = malloc(sizeof(int) * 2);
            ret[0] = it->val; ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        //���û���ҵ����Ͳ����ϣ����
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
