#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
//方法一：二进制想要得到每一位的一，可以通过 “%2”， “/2”的操作得到
//但是这个方法只适用于大于零的整数
//int count_one(int num)
//{
//	int cnt = 0;
//	while (num != 0)
//	{
//		if (num % 2 == 1)
//		{
//			cnt++;
//		}
//		num /= 2;
//	}
//	return cnt;
//}

//方法二：整形在内存中存储是以补码形式存储
//当其与 ‘1’ 按位与时，则全一出一，有零出零，以此判断其中有多少个一
//但此方法仍然需要循环32次
int count_one(int num)
{
	int cnt = 0;
	for (int i = 0; i < 32;i++)
	{
		if (((num >> i) & 1) == 1)
		{
			cnt++;
		}
	}
	return cnt;
}

//方法三：终极效率，但是比较难想到
//当 n = n & (n-1)时，每运行一次，就会去除二进制中最右边的 1 
int count_one(int num)
{
	int cnt = 0;
	while (num)
	{
		num = num & (num - 1);
		cnt++;
	}
	return cnt;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	int ret = count_one(num);
	printf("%d", ret);
	return 0;
}