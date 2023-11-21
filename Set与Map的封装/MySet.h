#pragma once
#pragma once
#include"RBTree.h"
namespace bit
{
	template<class K>
	class set
	{
	public:
		struct SetKeyofT//走一个过场，set只有key
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		//对于类模板取内嵌类型，要加typename告诉编译器这是类型
		typedef typename RBTree<K, K, SetKeyofT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyofT>::const_iterator const_iterator;
		iterator begin() const
		{
			return _t.begin();
		}
		iterator end() const
		{
			return _t.end();
		}

		//bool insert(const K& key)
		pair<iterator, bool> insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K, SetKeyofT> _t;
	};
}