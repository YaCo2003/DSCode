namespace MySet
{
	template<class K>
	class set
	{
	public:
		struct SetKeyofT//��һ��������setֻ��key
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		bool insert(const K& key)
		{
			return _t.Insert(key);
		}
	private:
		RBTree<K, K, SetKeyofT> _t;
	};
}