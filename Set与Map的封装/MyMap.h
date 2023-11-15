
namespace MyMap
{
	template<class K,class V>
	class map
	{
	public:
		struct MapKeyofT//ÔÚpairÖĞ·µ»Økey
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
		bool insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}
	private:
		RBTree<K, pair<K, V>, MapKeyofT> _t;
	};
}