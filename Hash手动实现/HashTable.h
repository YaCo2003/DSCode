#pragma once

namespace open_address
{
	//hashdata状态
	//为什么要有删除状态呢？
	//因为在查找的时候遇到数据状态为nullptr才会结束
	//如果没有删除状态，在删除一个data数据把他置为空的话
	//在后续查找的时候遇到空有可能会提前结束，查找是顺序查找
	enum Status
	{
		EMPTY,//空
		EXIST,//存在
		DELETE//删除
	};

	template<class K,class V>
	struct HashData
	{
		pair<K, V>_kv;
		Status _s;//状态
	};

	template<class K>
	struct HashFunc//数字直接转换
	{
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	template<>
	struct HashFunc<string>//模板特化
	{
		//字符串用每个字符ascii码相加
		size_t operator()(const string& key)
		{
			// BKDR哈希字符串
			//防止acb 和abc 重复
			size_t hash = 0;
			for (auto e : key)
			{
				hash *= 31;
				hash += e;
			}

			cout << key << ":" << hash << endl;
			return hash;
		}
	};
	//Hash为仿函数，用于数字转换
	template<class K, class V,class Hash = HashFunc<K>>
	class HashTable
	{		
	public:
		//初始化容量
		HashTable()
		{
			_tables.resize(10);
		}
		//插入,不能重复插入
		bool Insert(const pair<K, V>& _kv)
		{
			if (Find(_kv.first))
			{
				return false;
			}
			//负载因子为0.7就扩容
			if (_n * 10 / _tables.size() == 7)
			{
				size_t newSize = _tables.size() * 2;
				HashTable<K, V> newHT;
				newHT._tables.resize(newSize);
				//原来的表的值要重新映射
				// 遍历旧表
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._s == EXIST)
					{
						//这里相当于复用了原来的插入
						newHT.Insert(_tables[i]._kv);
					}
				}
				//交换表
				_tables.swap(newHT._tables);
			}
			Hash hf;
			size_t hashi = hf(_kv.first) % _tables.size();
			//先判断是否冲突
			//线性探测
			while (_tables[hashi]._s == EXIST)
			{
				hashi++;
				hashi %=_tables.size();
			}

			//开始插入
			_tables[hashi]._kv = _kv;
			_tables[hashi]._s = EXIST;
			_n++;//存储个数++

			return true;

		}
		//查找
		//如果Key是数字，可以查找，如果为string呢？
		//所以要有仿函数，把key转换为数字
		HashData<K, V>* Find(const K& key)
		{
			Hash hf;
			size_t hashi = hf(key) % _tables.size();
			int i = 0;
			while (_tables[hashi]._s != EMPTY)
			{
				//在这里必须加上一个条件_tables[hashi]._s == EXIST
				//因为删除是伪删除，只改变状态。如果只判断值是否相等的话，会出错
				//比如你删除了3，后面就无法插入3了
				//因为只判断值的话，这个第一个3并没有删除，无法插入
				if (_tables[hashi]._s == EXIST
					&&_tables[hashi]._kv.first == key)
				{
					return &_tables[hashi];
				}
				hashi++;
				hashi %= _tables.size();
			}

			return nullptr;
		}
		//伪删除，直接复用查找 
		bool Erase(const K& key)
		{
			HashData<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_s = DELETE;
				_n--;
				return true;
			}
			else
			{
				return false;
			}
		}
		void Print()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i]._s == EXIST)
				{
					//printf("[%d]->%d\n", i, _tables[i]._kv.first);
					cout << "[" << i << "]->" << _tables[i]._kv.first << ":" << _tables[i]._kv.second << endl;
				}
				else if (_tables[i]._s == EMPTY)
				{
					printf("[%d]->\n", i);
				}
				else
				{
					printf("[%d]->D\n", i);
				}
			}

			cout << endl;
		}
	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0; // 存储的关键字的个数
	};

	void TestHT1()
	{
		HashTable<int, int> ht;
		int a[] = { 4,14,24,34,5,7,1 };
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}

		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(-3, -3));
		ht.Print();

		ht.Erase(3);
		ht.Print();

		if (ht.Find(3))
		{
			cout << "3存在" << endl;
		}
		else
		{
			cout << "3不存在" << endl;
		}


		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(23, 3));
		ht.Print();
	}

	void TestHT2()
	{
		string arr[] = { "香蕉", "甜瓜","苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
		//HashTable<string, int, HashFuncString> ht;
		HashTable<string, int> ht;
		for (auto& e : arr)
		{
			//auto ret = ht.Find(e);
			HashData<string, int>* ret = ht.Find(e);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(e, 1));
			}
		}

		ht.Print();

		ht.Insert(make_pair("apple", 1));
		ht.Insert(make_pair("sort", 1));

		ht.Insert(make_pair("abc", 1));
		ht.Insert(make_pair("acb", 1));
		ht.Insert(make_pair("aad", 1));
		ht.Print();
	}
}

//哈希桶
namespace hash_tocket 
{
	template<class K, class V>
	struct HashNode
	{
		HashNode* _next;
		pair<K, V> _kv;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			, _next(nullptr)
		{}
	};

	template<class K, class V>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		HashTable()
		{
			_tables.resize(10);
		}
		~HashTable()
		{
			for (size_t i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_tables[i] = nullptr;
			}
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
				return false;
			//扩容，负载因子最大到1
			if (_n == _tables.size())
			{
				size_t newSize = _tables.size() * 2;
				HashTable<K, V> newHT;
				newHT._tables.resize(newSize);

				// 遍历旧表
				//方法1：浪费节点，因为要创建新的节点来插入，而原来的要析构
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						newHT.Insert(cur->_kv);
						cur = cur->_next;
					}
				}

				_tables.swap(newHT._tables);
			}
			//新建节点插入
			size_t hashi = kv.first % _tables.size();
			Node* newnode = new Node(kv);

			//头插
			newnode->_next = _tables[hashi];
			_tables[hashi]->_next = newnode;
			++_n;

			return true;
		}
		Node* Find(const K& key)
		{
			//....
			return NULL;
		}
	private:
		vector<Node*> _tables;
		size_t _n = 0;

	};
}
