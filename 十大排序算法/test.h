#include <iostream>
using namespace std;

// 排序实现的接口
void Print(int* a,int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
}
// 插入排序
void InsertSort(int* a, int n)
{
    //先排单趟，假设[0,end]有序，现在有一个数tmp，把它插入依旧有序
    //从后往前挨个比较，如果比tmp大，往后移动
    //int end;
    //int tmp;
    //while (end >= 0)
    //{
    //    if (tmp < a[end])
    //    {
    //        //比tmp大，往后移动
    //        a[end + 1] = a[end];
    //        --end;
    //    }
    //    else
    //    {
    //        //比tmp小，直接退出
    //        break;
    //    }
    //}
    // 

    //再排多趟
    for (int i = 1; i < n; i++)
    {
        int end = i - 1;
        int tmp = a[i];
        while (end >= 0)
        {
            if (tmp < a[end])
            {
                //比tmp大，往后移动
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                //比tmp小，直接退出
                break;
            }
        }
        //在这里有两种情况：
        //1.tmp太小，end是小于0退出的，此时end==-1，end+1刚好是a[0]位置，放入最小的tmp
        //2.tmp>a[end],此时直接往end+1位置插入tmp；
        a[end + 1] = tmp;
    }
}

// 希尔排序
void ShellSort(int* a, int n);
// 选择排序
void SelectSort(int* a, int n);
// 堆排序
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);
// 冒泡排序
void BubbleSort(int* a, int n)
{
    ////外层循环控制轮数
    //for (int round = 1; round < n-1; round++)
    //{
    //    //内层循环控制计算每轮比较次数
    //    for (int i = 0; i < n-round; i++)
    //    {
    //        if (a[i] > a[i+1])
    //        {
    //            int tmp = a[i];
    //            a[i] = a[i + 1];
    //            a[i + 1] = tmp;
    //            //swap(a[i], a[i+1]);
    //        }
    //    }
    //}
    //优化版本
    //外层循环控制轮数
    for (int round = 1; round < n-1; round++)
    {
        //内层循环控制计算每轮比较次数
        //定义一个判断是否在内层有交换
        bool hasSwap = false;
        for (int i = 0; i < n-round; i++)
        {
            if (a[i] > a[i+1])
            {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;

                hasSwap == true;
                //swap(a[i], a[i+1]);
            }
        }
        //如果没有交换，代表数组已经排好序
        if (!hasSwap)
        {
            break;
        }
    }
}
// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right);
// 快速排序挖坑法
int PartSort2(int* a, int left, int right);
// 快速排序前后指针法
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);
// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);
// 计数排序
void CountSort(int* a, int n);