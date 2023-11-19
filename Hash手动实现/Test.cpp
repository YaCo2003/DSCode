#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<set>
using namespace std;

#include"HashTable.h"

//²âÊÔmapÓëhashËÙ¶È
//int main()
//{
//	unordered_set<int> s;
//	s.insert(5);
//	s.insert(2);
//	s.insert(6);
//	s.insert(1);
//	s.insert(4);
//
//	unordered_set<int>::iterator it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	for (auto e : s)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	cout << s.load_factor() << endl;
//	cout << s.max_load_factor() << endl;
//
//	unordered_map<string, string> dict;
//	dict["sort"];
//	dict["sort"] = "ÅÅĞò";
//	dict["string"] = "×Ö·û´®";
//	dict["abc"] = "xx";
//
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//	cout << endl;
//
//	return 0;
//}

int main()
{
	//open_address::TestHT2();
	//hash_tocket::TestHT1();
	hash_tocket::TestHT2();

}