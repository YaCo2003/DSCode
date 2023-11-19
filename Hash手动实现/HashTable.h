#pragma once

template<class K>
struct HashFunc//����ֱ��ת��
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

template<>
struct HashFunc<string>//ģ���ػ�
{
	//�ַ�����ÿ���ַ�ascii�����
	size_t operator()(const string& key)
	{
		// BKDR��ϣ�ַ���
		//��ֹacb ��abc �ظ�
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

namespace open_address
{
	//hashdata״̬
	//ΪʲôҪ��ɾ��״̬�أ�
	//��Ϊ�ڲ��ҵ�ʱ����������״̬Ϊnullptr�Ż����
	//���û��ɾ��״̬����ɾ��һ��data���ݰ�����Ϊ�յĻ�
	//�ں������ҵ�ʱ���������п��ܻ���ǰ������������˳�����
	enum Status
	{
		EMPTY,//��
		EXIST,//����
		DELETE//ɾ��
	};

	template<class K,class V>
	struct HashData
	{
		pair<K, V>_kv;
		Status _s;//״̬
	};


	//HashΪ�º�������������ת��
	template<class K, class V,class Hash = HashFunc<K>>
	class HashTable
	{		
	public:
		//��ʼ������
		HashTable()
		{
			_tables.resize(10);
		}
		//����,�����ظ�����
		bool Insert(const pair<K, V>& _kv)
		{
			if (Find(_kv.first))
			{
				return false;
			}
			//��������Ϊ0.7������
			if (_n * 10 / _tables.size() == 7)
			{
				size_t newSize = _tables.size() * 2;
				HashTable<K, V> newHT;
				newHT._tables.resize(newSize);
				//ԭ���ı��ֵҪ����ӳ��
				// �����ɱ�
				for (size_t i = 0; i < _tables.size(); i++)
				{
					if (_tables[i]._s == EXIST)
					{
						//�����൱�ڸ�����ԭ���Ĳ���
						newHT.Insert(_tables[i]._kv);
					}
				}
				//������
				_tables.swap(newHT._tables);
			}
			Hash hf;
			size_t hashi = hf(_kv.first) % _tables.size();
			//���ж��Ƿ��ͻ
			//����̽��
			while (_tables[hashi]._s == EXIST)
			{
				hashi++;
				hashi %=_tables.size();
			}

			//��ʼ����
			_tables[hashi]._kv = _kv;
			_tables[hashi]._s = EXIST;
			_n++;//�洢����++

			return true;

		}
		//����
		//���Key�����֣����Բ��ң����Ϊstring�أ�
		//����Ҫ�зº�������keyת��Ϊ����
		HashData<K, V>* Find(const K& key)
		{
			Hash hf;
			size_t hashi = hf(key) % _tables.size();
			int i = 0;
			while (_tables[hashi]._s != EMPTY)
			{
				//������������һ������_tables[hashi]._s == EXIST
				//��Ϊɾ����αɾ����ֻ�ı�״̬�����ֻ�ж�ֵ�Ƿ���ȵĻ��������
				//������ɾ����3��������޷�����3��
				//��Ϊֻ�ж�ֵ�Ļ��������һ��3��û��ɾ�����޷�����
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
		//αɾ����ֱ�Ӹ��ò��� 
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
		size_t _n = 0; // �洢�Ĺؼ��ֵĸ���
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
			cout << "3����" << endl;
		}
		else
		{
			cout << "3������" << endl;
		}


		ht.Insert(make_pair(3, 3));
		ht.Insert(make_pair(23, 3));
		ht.Print();
	}

	void TestHT2()
	{
		string arr[] = { "�㽶", "���","ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
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

//��ϣͰ
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

	template<class K, class V, class Hash = HashFunc<K>>
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
			//���ݣ������������1
			if (_n == _tables.size())
			{
				//size_t newSize = _tables.size() * 2;
				//HashTable<K, V> newHT;
				//newHT._tables.resize(newSize);
				//// �����ɱ�
				////����1���˷ѽڵ㣬��ΪҪ�����µĽڵ������룬��ԭ����Ҫ����
				//for (size_t i = 0; i < _tables.size(); i++)
				//{
				//	Node* cur = _tables[i];
				//	while (cur)
				//	{
				//		newHT.Insert(cur->_kv);
				//		cur = cur->_next;
				//	}
				//}
				//_tables.swap(newHT._tables);

				//������
				vector<Node*> newTables;
				newTables.resize(_tables.size() * 2);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						//���½���ӳ�䣬Ų�����±�
						size_t hashi = hf(cur->_kv.first) % newTables.size();
						cur->_next = newTables[i];
						newTables[i] = cur;

						cur = next;
					}
					_tables[i] = nullptr;
				}
				_tables.swap(newTables);
			}
			//�½��ڵ����
			size_t hashi = hf(kv.first) % _tables.size();
			Node* newnode = new Node(kv);

			//ͷ��
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			++_n;

			return true;
		}
		Node* Find(const K& key)
		{
			size_t hashi = hf(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return NULL;
		}
		bool Erase(const K& key)
		{
			size_t hashi = hf(key) % _tables.size();
			Node* cur = _tables[hashi];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}
	private:
		vector<Node*> _tables;
		size_t _n = 0;
		Hash hf;

	};
	void TestHT1()
	{
		HashTable<int, int> ht;
		int a[] = { 4,14,24,34,5,7,1,15,25,3 };
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Insert(make_pair(33, 33));
		ht.Insert(make_pair(34, 34));

		cout << ht.Find(34) << endl;
		ht.Erase(34);
		cout << ht.Find(34) << endl;

	}
	void TestHT2()
	{
		string arr[] = { "�㽶", "���","ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
		//HashTable<string, int, HashFuncString> ht;
		HashTable<string, int> ht;
		for (auto& e : arr)
		{
			//auto ret = ht.Find(e);
			HashNode<string, int>* ret = ht.Find(e);
			if (ret)
			{
				ret->_kv.second++;
			}
			else
			{
				ht.Insert(make_pair(e, 1));
			}
		}

		cout << ht.Find("ƻ��") << endl;
		ht.Erase("ƻ��");
		cout << ht.Find("ƻ��") << endl;
	}
}
