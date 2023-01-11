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