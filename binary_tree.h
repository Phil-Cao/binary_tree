#pragma once
#ifndef _BINARY_SEARCH_TREE_HPP_
#define _BINARY_SEARCH_TREE_HPP_

#include<iostream>
#include<iomanip>
using namespace std;
template <class T>
class btnode
{
public:
	T key;
	btnode * left;
	btnode * right;
	btnode * father;

	btnode(T value, btnode * f, btnode * l, btnode * r) :key(value), father(), left(l), right(r) {}
};

template<class T>
class btree
{
private:
	btnode<T> * root;
public:
	btree();
	~btree();

	// 前序遍历"二叉树"
	void preorder();
    // 中序遍历"二叉树"
    void inorder();
	// 后序遍历"二叉树"
	void postorder();
	// (递归实现)查找"二叉树"中键值为key的节点
	btnode<T>* search(T key);
	// (非递归实现)查找"二叉树"中键值为key的节点
	btnode<T>* iterativeSearch(T key);

	// 查找最小结点：返回最小结点的键值。
	T minimum();
	// 查找最大结点：返回最大结点的键值。
	T maximum();

	// 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
	btnode<T>* successor(btnode<T> *x);
	// 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
	btnode<T>* predecessor(btnode<T> *x);

	// 将结点(key为节点键值)插入到二叉树中
	void insert(T key);

	// 删除结点(key为节点键值)
	void remove(T key);

	// 销毁二叉树
	void destroy();

	// 打印二叉树
	void print();
private:
	// 前序遍历"二叉树"
	void preorder(btnode<T>* tree) const;
	// 中序遍历"二叉树"
	void inorder(btnode<T>* tree) const;
	// 后序遍历"二叉树"
	void postorder(btnode<T>* tree) const;

	// (递归实现)查找"二叉树x"中键值为key的节点
	btnode<T>* search(btnode<T>* x, T key) const;
	// (非递归实现)查找"二叉树x"中键值为key的节点
	btnode<T>* iterativeSearch(btnode<T>* x, T key) const;

	// 查找最小结点：返回tree为根结点的二叉树的最小结点。
	btnode<T>* minimum(btnode<T>* tree);
	// 查找最大结点：返回tree为根结点的二叉树的最大结点。
	btnode<T>* maximum(btnode<T>* tree);

	// 将结点(z)插入到二叉树(tree)中
	void insert(btnode<T>* &tree, btnode<T>* z);

	// 删除二叉树(tree)中的结点(z)，并返回被删除的结点
	btnode<T>* remove(btnode<T>* &tree, btnode<T> *z);

	// 销毁二叉树
	void destroy(btnode<T>* &tree);

	// 打印二叉树
	void print(btnode<T>* tree, T key, int direction);
};

template<class T>
btree<T>::btree():root(NULL)
{

}

template<class T>
btree<T>::~btree()
{
	destory();
}

template<class T>
void btree<T>::preorder(btnode<T> * tree) const
{
	if (tree != NULL)
	{
		cout << tree->key << " ";
		preorder(tree->left);
		preorder(tree->right);
	}
}

template<class T>
void btree<T>::preorder()
{
	preorder(root);
}

template<class T>
void btree<T>::inorder(btnode<T> * tree) const
{
	if (tree != NULL)
	{
		inorder(tree->left);
		cout << tree->key << " ";
		inorder(tree->right);
	}
}

template<class T>
void btree<T>::inorder()
{
	inorder(root);
}

template<class T>
void btree<T>::postorder(btnode<T> * tree) const
{
	if (tree != NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		cout << tree->key << " ";
	}
}

template<class T>
void btree<T>::postorder()
{
	postorder(root);
}

template<class T>
btnode<T>* btree<T>::search(btnode<T> * x, T key) const
{
	if (x == NULL || x->key == key)
		return x;

	if (key < x->key)
		return search(x->left,key);
	else
		return search(x->right,key);
}

template<class T>
btnode<T>* btree<T>::search(T key)
{
	search(root, key);
}

template<class T>
btnode<T>* btree<T>::iterativeSearch(btnode<T> * x, T key) const
{
	while ((x != NULL) && (x->key != key))
	{
		if (x->key < key)
			x = x->left;
		else
			x = x->right;
	}

	return x;
}

template<class T>
btnode<T>* btree<T>::iterativeSearch(T key)
{
	iterativeSearch(root, key);
}

template <class T>
btnode<T>* btree<T>::minimum(btnode<T>* tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

template <class T>
T btree<T>::minimum()
{
	btnode<T> * p = minimum(root);
	if (p != NULL)
		return p->key;
	else
		return (T)NULL; 
}

template <class T>
btnode<T>* btree<T>::maximum(btnode<T>* tree)
{
	if (tree == NULL)
		return NULL;

	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

template <class T>
T btree<T>::maximum()
{
	btnode<T> * p = maximum(root);
	if (p != NULL)
		return p->key;
	else
		return (T)NULL; 
}

template <class T>
btnode<T>* btree<T>::successor(btnode<T> *x)
{
	if (x->right != NULL)
		return minimum(x->right);

	btnode<T> * y = x->father;
	while ((y != NULL) && (y->right == x))
	{
		x = y;
		y = y->father;
	}

	return y;
}

template <class T>
btnode<T>* btree<T>::predecessor(btnode<T> *x)
{
	if (x->left != NULL)
		return minimum(x->left);

	btnode<T> * y = x->father;
	while ((y != NULL) && (y->left == x))
	{
		x = y;
		y = y->father;
	}

	return y;
}

template <class T>
void btree<T>::insert(btnode<T>* &tree, btnode<T>* z)
{
	btnode<T> * y = NULL;
	btnode<T> * x = tree;

	// 查找z的插入位置
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	z->father = y;
	if (y == NULL)
		tree = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

template <class T>
void btree<T>::insert(T key)
{
	btnode<T> *z = NULL;

	// 如果新建结点失败，则返回。
	z = new btnode<T>(key, NULL, NULL, NULL);

	insert(root, z);
}

template <class T>
btnode<T>* btree<T>::remove(btnode<T>* &tree, btnode<T> *z)
{
	btnode<T> * x = NULL;
	btnode<T> * y = NULL;

	if ((z->left == NULL) || (z->right == NULL))
		y = z;
	else
		y = successor(z);

	if (y->left != NULL)
		x = y->left;
	else
		x = y->right;

	if (x != NULL)
		x->father = y->father;

	if (y->father == NULL)
		tree = x;
	else if (y == y->father->left)
		y->father->left = x;
	else
		y->father->right = x;

	if (y != z)
		z->key = y->key;

	return y;
}

template <class T>
void btree<T>::remove(T key)
{
	btnode<T> * z, * node;

	if ((z = search(root, key)) != NULL)
		if ((node = remove(root, z)) != NULL)
			delete node;
}

template <class T>
void btree<T>::destroy(btnode<T>* &tree)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL)
		return destroy(tree->left);
	if (tree->right != NULL)
		return destroy(tree->right);

	delete tree;
	tree = NULL;
}

template <class T>
void btree<T>::destroy()
{
	destroy(root);
}

template <class T>
void btree<T>::print(btnode<T>* tree, T key, int direction)
{
	if (tree != NULL)
	{
		if (direction == 0)    // tree是根节点
			cout << setw(2) << tree->key << " is root" << endl;
		else                // tree是分支节点
			cout << setw(2) << tree->key << " is " << setw(2) << key << "'s " << setw(12) << (direction == 1 ? "right child" : "left child") << endl;

		print(tree->left, tree->key, -1);
		print(tree->right, tree->key, 1);
	}
}

template <class T>
void btree<T>::print()
{
	if (root != NULL)
		print(root, root->key, 0);
}
#endif