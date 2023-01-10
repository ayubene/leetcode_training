#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int p1 = m-1, p2 = n-1;
	int index = m + n - 1;
	int cur;
	while ((p1 != -1 || p2 != -1)&&index!=-1) {
		if (p1 == -1) {
			cur = nums2[p2];
			p2--;
		}
		else if (p2 == -1) {
			cur = nums1[p1];
			p1--;
		}
		else if (nums1[p1] > nums2[p2]) {
			cur = nums1[p1];
			p1--;
		}
		else {
			cur = nums2[p2];
			p2--;
		}
		nums1[index] = cur;
		index--;
	}

}

int main() {
	int nums1[] = { 1, 2, 3, 0, 0, 0 };
	int nums2[] = { 2, 5, 6 };
	int m = 3, n = 3;
	int numsSize = 9;
	merge(nums1, 6, 3, nums2, 3 , 3);
	for (int i = 0; i < m + n; i++)
	{
		printf("%3d\n", nums1[i]);
	}

} 

/*
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int p1 = m - 1, p2 = n - 1;
	int tail = m + n - 1;
	int cur;
	while (p1 >= 0 || p2 >= 0) {
		if (p1 == -1) {
			cur = nums2[p2--];
		} else if (p2 == -1) {
			cur = nums1[p1--];
		} else if (nums1[p1] > nums2[p2]) {
			cur = nums1[p1--];
		} else {
			cur = nums2[p2--];
		}
		nums1[tail--] = cur;
	}
}
*/