/* 
	哈希方法有两种，一种是计数，最后遍历一遍如果等于1即要找的
	一种是记下该字母出现的索引，如果字母已存在，将索引改为-1即可
*/
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

struct hashTable* hashtable;

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
    //如果所给数组中有相同的key值， 下标值改为-1
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