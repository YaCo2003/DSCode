#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//
//�������� :
//
//1999 2299
//
//������� : 7
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