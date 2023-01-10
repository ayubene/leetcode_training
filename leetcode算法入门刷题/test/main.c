//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void swap1(int a, int b)
{
	int tmp = a;
	b = a, a = tmp;

}
void swap2(int* pa, int* pb)
{
	int tmp = *pa;
	*pa = *pb, * pb = tmp;
}
int main()
{
	int x = 10, y = 20;
	printf("%d,%d\n", x, y);
	swap1(&x, &y);
	printf("%d,%d\n", x, y);
	return 0;
}