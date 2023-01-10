#include<stdlib.h>
int cmp(int* a, int* b) {
	return *a - *b;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	for (int i = m; i < m + n; i++) {
		nums1[i] = nums2[i - m];
	}
	qsort(nums1, nums1Size, sizeof(int), cmp);
}