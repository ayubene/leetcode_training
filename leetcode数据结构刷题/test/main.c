#include <stdio.h>
int test(int* ip)
{
	*ip = 2;
}
int main()
{
	int  var = 20;   /* 实际变量的声明 */
	int* a = malloc(sizeof(int) * 3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	int* ip = a;       /* 指针变量的声明 */
	printf("ip 变量存储的地址: %p\n", ip);
	//ip = &var;  /* 在指针变量中存储 var 的地址 */

	printf("var 变量的地址: %p\n", &var);

	/* 在指针变量中存储的地址 */
	//printf("ip 变量存储的地址: %p\n", ip);

	/* 使用指针访问值 */
	printf("*ip 变量的值: %d\n", *ip);
	ip=ip + 1;
	ip = ip + 1;
	ip = ip + 1;
	printf("*ip 变量的值: %d\n", *ip);
	test(ip);

	int d[5][3] = { {80,75,92}, {61,65,71}, {59,63,70}, {85,87,90}, {76,77,85} };
	printf("d[0][0]的值: %d\n", d);

	int ch = 'd';
	printf("char%d/n", ch - 'a');

	return 0;
}