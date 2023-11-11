#pragma once
#include <iostream>
#include <string>
using namespace std;
template<class T>
struct BSTreeNode
{
	BSTreeNode(const T& data)
		:_left(nullptr), _right(nullptr), _data(data)
	{
	}

	BSTreeNode<T>* _left;
	BSTreeNode<T>* _right;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTreeNode<T> Node;
public:

	bool BSTreeInit(const T& data)
	{
		if(_root==nullptr)
		{
			_root = new Node(data);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data > cur->_data)
			{
				cur = cur->_right;
			}
			else if (data < cur->_data)
			{
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(data);
		if (data > parent->_data)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}
	//查找
	bool Find(const T& data)
	{
		Node* cur = _root;
		while (cur)
		{
			if (data > cur->_data)
			{
				cur = cur->_right;
			}
			else if (data > cur->_data)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool Erase(const T& data)
	{
		Node* cur = _root;
		Node* parent = nullptr;
		while(cur)
		{		
			
			if (data > cur->_data)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (data < cur->_data)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//找到了，删除
				if (cur->_left == nullptr)//左为空
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						//判断
						if (cur == parent->_left)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}		
				}
				else if (cur->_right == nullptr)//右为空
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						//判断
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
				}
				else//左右都不为空，，找左树最大节点，或者右树最小节点
				{
					//右树最小节点（最左节点）
					Node* parent = cur;
					Node* subleft = cur->_right;
					while (subleft->_left)
					{
						parent = subleft;
						subleft = subleft->_left;
					}

					swap(cur->_data, subleft->_data);

					if (subleft == parent->_left)
					{
						parent->_left = subleft->_right;
					}
					else
					{
						parent->_right = subleft->_right;
					}
				}
				return true;
			}
		}
		return false;
	}

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}
	//查找递归版本
	bool FindR(const T& data)
	{
		return _FindR(_root, data);
	}
	//插入递归版本
	bool BSTreeInitR(const T& data)
	{
		return _BSTreeInitR(_root, data);
	}
	//删除
	bool EraseR(const T& data)
	{
		return _EraseR(_root, data);
	}
private:
	bool _EraseR(Node*& root, const T& data)
	{
		if (root == nullptr)
			return false;

		if (data < root->_data)
		{
			return _EraseR(root->_left, data);
		}
		else if (data > root->_data)
		{
			return _EraseR(root->_right, data);
		}
		else
		{
			//找到了，删除
			if (root->_left == nullptr)//左为空
			{
				Node* del = root;
				root = root->_right;
				return true;
			}
			else if (root->_right == nullptr)//右为空
			{
				Node* del = root;
				root = root->_left;
				return true;
			}
			else//左右都不为空
			{
				Node* subleft = root->_right;
				while (subleft->_left)
				{
					subleft = subleft->_left;
				}

				swap(root->_data, subleft->_data);

				return _EraseR(root->_right, data);
			}
		}
	}
	bool _FindR(Node* root, const T& data)
	{
		if (root == nullptr)
			return false;

		if (data < root->_data)
		{
			return _FindR(root->_left, data);
		}
		else if(data > root->_data)
		{
			return _FindR(root->_right, data);
		}
		else
		{
			return true;
		}
	}

	bool _BSTreeInitR(Node*& root, const T& data)
	{
		if (root == nullptr)
		{
			root = new Node(data);
			return true;
		}

		if (data < root->_data)
		{
			return _BSTreeInitR(root->_left, data);
		}
		else if (data > root->_data)
		{
			return _BSTreeInitR(root->_right, data);
		}
		else
		{
			return false;
		}
	}

	//遍历打印
	void _Inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_Inorder(root->_left);
		cout << root->_data << " ";
		_Inorder(root->_right);
	}
	Node* _root = nullptr;
};
