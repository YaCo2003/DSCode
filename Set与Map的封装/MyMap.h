
namespace MyMap
{
	template<class K,class V>
	class map
	{
	public:
		struct MapKeyofT//��pair�з���key
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