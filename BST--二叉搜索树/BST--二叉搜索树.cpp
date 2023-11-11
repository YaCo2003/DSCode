// BST--二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "BSTree.h"
//void TestBSTree()
//{
//	BSTree<string, string> dict;
//	dict.Insert("insert", "插入");
//	dict.Insert("erase", "删除");
//	dict.Insert("left", "左边");
//	dict.Insert("string", "字符串");
//
//	string str;
//	while (cin >> str)
//	{
//		auto ret = dict.Find(str);
//		if (ret)
//		{
//			cout << str << ":" << ret->_value << endl;
//		}
//		else
//		{
//			cout << "单词拼写错误" << endl;
//		}
//	}
//
//	string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
//	// 统计水果出现的次
//	BSTree<string, int> countTree;
//	for (auto str : strs)
//	{
//		auto ret = countTree.Find(str);
//		if (ret == NULL)
//		{
//			countTree.Insert(str, 1);
//		}
//		else
//		{
//			ret->_value++;
//		}
//	}
//	countTree.InOrder();
//}

int main()
{
    int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
    BSTree<int> BT;
    for (auto e : a)
    {
        BT.BSTreeInitR(e);
    }
    BT.Inorder();

    BT.EraseR(8);
    BT.Inorder();
    //cout << BT.FindR(14);
    for (auto e : a)
    {
        BT.EraseR(e);
        BT.Inorder();
    }
    return 0;

}

