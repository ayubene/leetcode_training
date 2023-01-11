/* 
	��ϣ���������֣�һ���Ǽ�����������һ���������1��Ҫ�ҵ�
	һ���Ǽ��¸���ĸ���ֵ������������ĸ�Ѵ��ڣ���������Ϊ-1����
*/
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

struct hashTable* hashtable;

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
    //�����������������ͬ��keyֵ�� �±�ֵ��Ϊ-1
    else {
        it->val = -1;
    }
}

int firstUniqChar(char* s) {
    hashtable = NULL;
    int ret = -1;
    for (int i = 0; s[i] != '\0'; i++) {
        insert(s[i]-'0', i);
    }
    for (int i = 0; s[i] != '\0'; i++) {
        struct hashTable* it = find(s[i]-'0');
        if (it->val != -1) {
            ret = it->val;
            break;
        }
    }
    return ret;
}