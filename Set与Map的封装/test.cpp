#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include "RBTree.h"

//int main()
//{
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	int a[] = { 790,760,969,270,31,424,377,24,702 };
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		if (e == 702)
//		{
//			int i = 0;
//		}
//
//		cout << "Insert:" << e << "->";
//		t.Insert(make_pair(e, e));
//		cout << t.IsBalance() << endl;
//	}
//	t.InOrder();
//
//	cout << t.IsBalance() << endl;
//
//	return 0;
//}

//int main()
//{
//	const int N = 10000000;
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//
//	for (size_t i = 0; i < N; i++)
//	{
//		v.push_back(rand() + i);
//		//cout << v.back() << endl;
//	}
//
//	size_t begin2 = clock();
//	RBTree<int, int> t;
//	for (auto e : v)
//	{
//		if (e == 29365)
//		{
//			int i = 0;
//		}
//
//		//cout << "Insert:" << e << "->";
//		t.Insert(make_pair(e, e));
//		//cout << t.IsBalance() << endl;
//	}
//	size_t end2 = clock();
//
//	cout << "Insert:" << end2 - begin2 << endl;
//
//	cout << t.IsBalance() << endl;
//	cout << t.Height() << endl;
//	cout << t.Size() << endl;
//
//	size_t begin1 = clock();
//	for (auto e : v)
//	{
//		t.Find(e);
//	}
//
//	for (size_t i = 0; i < N; i++)
//	{
//		t.Find((rand() + i));
//	}
//
//	size_t end1 = clock();
//
//	cout << "Find:" << end1 - begin1 << endl;
//
//	return 0;
//}

#include"MyMap.h"
#include"MySet.h"

void test_set()
{
	bit::set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(2);
	s.insert(0);
	s.insert(10);
	s.insert(5);


	bit::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it += 1;
		cout << *it << " ";
		++it;
		//--it;
	}
	cout << endl;

	//// key
	it = s.begin();
	++it;
	cout << *it << " " << endl;
	//*it = 100;

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_map()
{
	bit::map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("sort", "xx"));
	dict.insert(make_pair("left", "左"));
	dict.insert(make_pair("right", "右"));

	bit::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// key޸
		//it->first += 'x';
		it->second += 'y';
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	//次数统计：
	string arr[] = { "香蕉", "甜瓜","苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	bit::map<string, int> countmap;
	for (auto& e : arr)
	{
		countmap[e]++;
	}

	for (auto& kv : countmap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	cout << endl;
}
int main()
{
	test_map();
	test_set();

	return 0;
}