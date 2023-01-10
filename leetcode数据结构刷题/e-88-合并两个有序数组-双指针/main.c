#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int* p1 = nums1;
	int* p2 = nums2;
	int* nums = malloc(sizeof(int) * (m + n));
	int mm = m, nn = n;
	for (int i = 0; i < m + n; i++) {
		if (mm == 0) {
			for (int j = i; j < m+n; j++) {
				nums[j] = nums2[j-m];
			}
			for (int i = 0; i != m + n; ++i) {
				nums1[i] = nums[i];
			}
			return;
		}
		if (nn == 0) {
			for (int j = i; j < m + n; j++) {
				nums[j] = nums1[j - n];
			}
			for (int i = 0; i != m + n; ++i) {
				nums1[i] = nums[i];
			}
			return;
		}
		if (*p1 < *p2) {
			nums[i] = *p1;
			p1++;
			mm--;
		}
		else {
			nums[i] = *p2;
			p2++;
			nn--;
		}
	}
	for (int i = 0; i != m + n; ++i) {
		nums1[i] = nums[i];
	}
}

int main() {
	int nums1[] = { 2,0 };
	int nums2[] = { 1 };
	int m = 1, n = 1;
	int numsSize = 9;
	merge(nums1, 2, 1, nums2, 1,1);
	for (int i = 0; i < m + n; i++)
	{
		printf("%3d\n", nums1[i]);
	}
	
}

/*
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int p1 = 0, p2 = 0;
	int sorted[m + n];
	int cur;
	while (p1 < m || p2 < n) {
		if (p1 == m) {
			cur = nums2[p2++];
		} else if (p2 == n) {
			cur = nums1[p1++];
		} else if (nums1[p1] < nums2[p2]) {
			cur = nums1[p1++];
		} else {
			cur = nums2[p2++];
		}
		sorted[p1 + p2 - 1] = cur;
	}
	for (int i = 0; i != m + n; ++i) {
		nums1[i] = sorted[i];
	}
}

*/