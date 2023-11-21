#pragma once

enum Colour
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K,V> Node;
public:
	//插入  插入新节点统一为红
	bool Insert(const pair<K,V>& kv)
	{
		//根节点为黑
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		//寻找插入位置
		//满足二叉搜索树性质
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		//走到这里 cur=nullptr
		//新增节点
		cur = new Node(kv);
		cur->_col = RED;
		//判断在parent的左边还是右边插入
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}

		//插入完成后要考虑此时是否平衡
		//情况1，如果parent为黑，不用管
		//情况2，如果parent为红
		while (parent && parent->_col == RED)
		{
			//此时要考虑parent的叔叔
			//也就是parent->parent的另外一个子节点
			Node* grandfather = parent->_parent;
			//此时parent可能为左，也可能为右
			if (parent == grandfather->_left)
			{
				//     g
				//   p    u
				// c
				Node* uncle = grandfather->_right;
				//此时又有叔叔两种情况
				//1.叔叔为存在且为红
				if (uncle && uncle->_col == RED)
				{
					//由于c和p此时都为红，不满足rbtree条件
					//所以要变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续往上更新处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else//2.叔叔不存在或者为黑
				{
					//此时cur要判断在parent的左边还是右边
					if (cur == parent->_left)
					{
						//右单旋
						//     g
						//   p    
						// c
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						// 双旋
						//     g
						//   p
						//     c
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else//parent在右边
			{
				//     g
				//   u   p 
				//          c
				Node* uncle = grandfather->_left;
				//1.叔叔为存在且为红
				if (uncle && uncle->_col == RED)
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续往上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else//2.叔叔不存在或者为黑
				{
					if (cur == parent->_right)
					{
						//     g
						//   u   p 
						//			c
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//     g
						//   u   p 
						//     c
						//双旋本质 cur变成根
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;

					}
					break;
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}
	//左单旋
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		subR->_left = parent;

		//记录parent的parent
		Node* parentParent = parent->_parent;

		parent->_parent = subR;
		if (subRL)//可能为空
		{
			subRL->_parent = parent;
		}

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subR;
			}
			else
			{
				parentParent->_right = subR;
			}
			subR->_parent = parentParent;
		}
	}
	//右单旋
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		subL->_right = parent;

		//记录parent的parent
		Node* parentParent = parent->_parent;

		parent->_parent = subL;
		if (subLR)//可能为空
		{
			subLR->_parent = parent;
		}

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
			{
				parentParent->_left = subL;
			}
			else
			{
				parentParent->_right = subL;
			}
			subL->_parent = parentParent;
		}
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	//中序遍历
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	// 根节点->当前节点这条路径的黑色节点的数量
	bool Check(Node* root, int blacknum, const int refVal)
	{
		if (root == nullptr)
		{
			//cout << balcknum << endl;
			if (blacknum != refVal)
			{
				cout << "存在黑色节点数量不相等的路径" << endl;
				return false;
			}

			return true;
		}

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "有连续的红色节点" << endl;

			return false;
		}

		if (root->_col == BLACK)
		{
			++blacknum;
		}

		return Check(root->_left, blacknum, refVal)
			&& Check(root->_right, blacknum, refVal);
	}

	bool IsBalance()
	{
		if (_root == nullptr)
			return true;

		if (_root->_col == RED)
			return false;

		//参考值
		int refVal = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				++refVal;
			}

			cur = cur->_left;
		}

		int blacknum = 0;
		return Check(_root, blacknum, refVal);
	}

private:
	Node* _root = nullptr;
};

