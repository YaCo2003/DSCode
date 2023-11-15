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
	MySet::set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(2);
	s.insert(0);
	s.insert(10);
	s.insert(5);

	//MySet::set<int>::iterator it = s.begin();
	//while (it != s.end())
	//{
	//	*it += 1;

	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	//// key޸
	//it = s.begin();
	//*it = 100;

	//for (auto e : s)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
}

void test_map()
{
	MyMap::map<string, string> dict;
	dict.insert(make_pair("sort", ""));
	dict.insert(make_pair("sort", "xx"));
	dict.insert(make_pair("left", ""));
	dict.insert(make_pair("right", "ұ"));

	//MyMap::map<string, string>::iterator it = dict.begin();
	//while (it != dict.end())
	//{
	//	// key޸
	//	it->first += 'x';
	//	it->second += 'y';

	//	cout << it->first << ":" << it->second << endl;
	//	++it;
	//}
	//cout << endl;

	//string arr[] = { "㽶", "","ƻ", "", "ƻ", "", "ƻ", "ƻ", "", "ƻ", "㽶", "ƻ", "㽶" };
	//MyMap::map<string, int> countMap;
	//for (auto& e : arr)
	//{
	//	countMap[e]++;
	//}

	//for (auto& kv : countMap)
	//{
	//	cout << kv.first << ":" << kv.second << endl;
	//}
	//cout << endl;
}

int main()
{
	test_map();
	test_set();

	return 0;
}