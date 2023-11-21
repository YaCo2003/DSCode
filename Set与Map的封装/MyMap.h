#pragma once
#include"RBTree.h"
namespace bit
{
	template<class K, class V>
	class map
	{
	public:
		struct MapKeyofT//在pair中返回key
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

		typedef typename RBTree<K, pair<const K, V>, MapKeyofT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyofT>::const_iterator const_iterator;
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}

		//有-》查询，没有-》插入
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}
		//bool insert(const pair<K, V>& kv)
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}
	private:
		RBTree<K, pair<const K, V>, MapKeyofT> _t;
	};
}