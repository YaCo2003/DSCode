#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
//����һ����������Ҫ�õ�ÿһλ��һ������ͨ�� ��%2���� ��/2���Ĳ����õ�
//�����������ֻ�����ڴ����������
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

//���������������ڴ��д洢���Բ�����ʽ�洢
//������ ��1�� ��λ��ʱ����ȫһ��һ��������㣬�Դ��ж������ж��ٸ�һ
//���˷�����Ȼ��Ҫѭ��32��
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

//���������ռ�Ч�ʣ����ǱȽ����뵽
//�� n = n & (n-1)ʱ��ÿ����һ�Σ��ͻ�ȥ�������������ұߵ� 1 
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