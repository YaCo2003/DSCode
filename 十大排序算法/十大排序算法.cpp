// 十大排序算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"test.h"

int main()
{
    int a[] = { 0,5,6,3,2,1,4,7,9,8 };
    int n = sizeof(a) / sizeof(a[0]);
    /*Print(a, n);
    InsertSort(a,n);
    Print(a, n);*/

    Print(a, n);
    BubbleSort(a, n);
    Print(a, n);

    return 0;

}

