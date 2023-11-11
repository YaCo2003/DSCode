#include <iostream>
using namespace std;

// ����ʵ�ֵĽӿ�
void Print(int* a,int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
}
// ��������
void InsertSort(int* a, int n)
{
    //���ŵ��ˣ�����[0,end]����������һ����tmp������������������
    //�Ӻ���ǰ�����Ƚϣ������tmp�������ƶ�
    //int end;
    //int tmp;
    //while (end >= 0)
    //{
    //    if (tmp < a[end])
    //    {
    //        //��tmp�������ƶ�
    //        a[end + 1] = a[end];
    //        --end;
    //    }
    //    else
    //    {
    //        //��tmpС��ֱ���˳�
    //        break;
    //    }
    //}
    // 

    //���Ŷ���
    for (int i = 1; i < n; i++)
    {
        int end = i - 1;
        int tmp = a[i];
        while (end >= 0)
        {
            if (tmp < a[end])
            {
                //��tmp�������ƶ�
                a[end + 1] = a[end];
                --end;
            }
            else
            {
                //��tmpС��ֱ���˳�
                break;
            }
        }
        //�����������������
        //1.tmp̫С��end��С��0�˳��ģ���ʱend==-1��end+1�պ���a[0]λ�ã�������С��tmp
        //2.tmp>a[end],��ʱֱ����end+1λ�ò���tmp��
        a[end + 1] = tmp;
    }
}

// ϣ������
void ShellSort(int* a, int n);
// ѡ������
void SelectSort(int* a, int n);
// ������
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);
// ð������
void BubbleSort(int* a, int n)
{
    ////���ѭ����������
    //for (int round = 1; round < n-1; round++)
    //{
    //    //�ڲ�ѭ�����Ƽ���ÿ�ֱȽϴ���
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
    //�Ż��汾
    //���ѭ����������
    for (int round = 1; round < n-1; round++)
    {
        //�ڲ�ѭ�����Ƽ���ÿ�ֱȽϴ���
        //����һ���ж��Ƿ����ڲ��н���
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
        //���û�н��������������Ѿ��ź���
        if (!hasSwap)
        {
            break;
        }
    }
}
// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right);
// ���������ڿӷ�
int PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right);
void QuickSort(int* a, int left, int right);
// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);
// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);
// ��������
void CountSort(int* a, int n);