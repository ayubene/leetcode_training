#include <stdio.h>
int test(int* ip)
{
	*ip = 2;
}
int main()
{
	int  var = 20;   /* ʵ�ʱ��������� */
	int* a = malloc(sizeof(int) * 3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	int* ip = a;       /* ָ����������� */
	printf("ip �����洢�ĵ�ַ: %p\n", ip);
	//ip = &var;  /* ��ָ������д洢 var �ĵ�ַ */

	printf("var �����ĵ�ַ: %p\n", &var);

	/* ��ָ������д洢�ĵ�ַ */
	//printf("ip �����洢�ĵ�ַ: %p\n", ip);

	/* ʹ��ָ�����ֵ */
	printf("*ip ������ֵ: %d\n", *ip);
	ip=ip + 1;
	ip = ip + 1;
	ip = ip + 1;
	printf("*ip ������ֵ: %d\n", *ip);
	test(ip);

	int d[5][3] = { {80,75,92}, {61,65,71}, {59,63,70}, {85,87,90}, {76,77,85} };
	printf("d[0][0]��ֵ: %d\n", d);

	int ch = 'd';
	printf("char%d/n", ch - 'a');

	return 0;
}