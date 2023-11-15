#pragma once
#pragma once


enum Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

//class T��������Ķ���1.key  2.key/value
//data��
//����set->RBTree<K,K> _t;
//����map->RBTree<K, pair<K, T>> _t;
//��������������������һ���º���KeyofT
// 
//����set->RBTree<K, K, SetKeyofT> _t;
//����map->RBTree<K, pair<K, T>, MapKeyofT> _t;
template<class K, class T, class KeyofT>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	//����  �����½ڵ�ͳһΪ��
	bool Insert(const T& data)
	{
		//���ڵ�Ϊ��
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		//�����㴫����ʲô������һ��keyoft
		//���ǱȽϴ�С������kot����
		KeyofT kot;
		//Ѱ�Ҳ���λ��
		//�����������������
		while (cur)
		{
			//����T������ֱ�ӱȽϴ�С�޷��ж���key�Ƚϻ���pair<key,value>�Ƚ�
			//������Ҫ��data���keyȡ�����Ƚ�
			//data==key  ->key
			//data==pair ->key
			//ͨ��KeyofT kot; ��keyȡ����
			if (kot(data) > kot(cur->_data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(data) < kot(cur->_data))
			{
				parent = cur;
				cur = cur->_left;
			}
		}

		//�ߵ����� cur=nullptr
		//�����ڵ�
		cur = new Node(data);
		cur->_col = RED;
		//�ж���parent����߻����ұ߲���
		if (kot(parent->_data) > kot(cur->_data))
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//������ɺ�Ҫ���Ǵ�ʱ�Ƿ�ƽ��
		//���1�����parentΪ�ڣ����ù�
		//���2�����parentΪ��
		while (parent && parent->_col == RED)
		{
			//��ʱҪ����parent������
			//Ҳ����parent->parent������һ���ӽڵ�
			Node* grandfather = parent->_parent;
			//��ʱparent����Ϊ��Ҳ����Ϊ��
			if (parent == grandfather->_left)
			{
				//     g
				//   p    u
				// c
				Node* uncle = grandfather->_right;
				//��ʱ���������������
				//1.����Ϊ������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					//����c��p��ʱ��Ϊ�죬������rbtree����
					//����Ҫ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//�������ϸ��´���
					cur = grandfather;
					parent = cur->_parent;
				}
				else//2.���岻���ڻ���Ϊ��
				{
					//��ʱcurҪ�ж���parent����߻����ұ�
					if (cur == parent->_left)
					{
						//�ҵ���
						//     g
						//   p    
						// c
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						// ˫��
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
			else//parent���ұ�
			{
				//     g
				//   u   p 
				//          c
				Node* uncle = grandfather->_left;
				//1.����Ϊ������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					// ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else//2.���岻���ڻ���Ϊ��
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
						//˫������ cur��ɸ�
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
	//����
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		subR->_left = parent;

		//��¼parent��parent
		Node* parentParent = parent->_parent;

		parent->_parent = subR;
		if (subRL)//����Ϊ��
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
	//�ҵ���
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		subL->_right = parent;

		//��¼parent��parent
		Node* parentParent = parent->_parent;

		parent->_parent = subL;
		if (subLR)//����Ϊ��
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
	//�������
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << " ";
		_InOrder(root->_right);
	}

	// ���ڵ�->��ǰ�ڵ�����·���ĺ�ɫ�ڵ������
	bool Check(Node* root, int blacknum, const int refVal)
	{
		if (root == nullptr)
		{
			//cout << balcknum << endl;
			if (blacknum != refVal)
			{
				cout << "���ں�ɫ�ڵ���������ȵ�·��" << endl;
				return false;
			}

			return true;
		}

		if (root->_col == RED && root->_parent->_col == RED)
		{
			cout << "�������ĺ�ɫ�ڵ�" << endl;

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

		//�ο�ֵ
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

