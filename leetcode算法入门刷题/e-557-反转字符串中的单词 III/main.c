#include<stdio.h>
#include<stdlib.h>

void swap(char* a, char* b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverseString(char* s, int left,int right) {
	//int left = 0, right = sSize - 1;
	while (left < right) {
		swap(&s[left], &s[right]);
		left++; right--;
	}
}

char* reverseWords(char* s) {
	int left = 0, right = 0;
	while (s[right] != '\0') {
		if (s[right] != ' ') {
			right++;
		}
		else {
			reverseString(s,left,right-1);
			right++;
			left = right;
		}
	}
	reverseString(s, left, right - 1);
	return s;
}


int main() {
	//char s[5] = "hello";
	//char s[6] = { 'H','e','l','l','o' };
	//char s[] = { "h","e","l","l","o" };
	char s[9] = "God Ding";
	int sSize = 5;
	int k = 2;
	int* returnSzie;
	int a = 10;
	returnSzie = &a;
	reverseWords(s);
	for (int i = 0; i < sSize; i++) {
		printf("%c\n", s[i]);
	}
}