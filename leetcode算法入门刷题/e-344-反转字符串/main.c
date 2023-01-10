#include<stdio.h>
#include<stdlib.h>

void swap(char* a, char* b) {
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
void reverseString(char* s, int sSize) {
	int left = 0, right = sSize-1;
	while (left < right) {
		swap(&s[left], &s[right]);
		left++; right--;
	}
}

int main() {
	//char s[5] = "hello";
	char s[6] = { 'H','e','l','l','o' };
	//char s[] = { "h","e","l","l","o" };
	int sSize = 5;
	int k = 2;
	int* returnSzie;
	int a = 10;
	returnSzie = &a;
	reverseString(s, sSize);
	for (int i = 0; i < sSize; i++) {
		printf("%c\n", s[i]);
	}
}