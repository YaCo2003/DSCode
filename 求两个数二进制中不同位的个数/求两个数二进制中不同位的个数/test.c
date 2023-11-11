#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//
//输入例子 :
//
//1999 2299
//
//输出例子 : 7
int main()
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	int cnt = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((num1 >> i) & 1) != ((num2 >> i) & 1))
		{
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}