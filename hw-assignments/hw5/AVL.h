#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

class node
{
public:
	node* left;
	node* right;
	int data;
	int height;
	node(int k)
	{
		data = k;
		left = nullptr;
		right = nullptr;
		height = 0;
	}
};

class AVL
{
public:
	AVL()
	{
		root = nullptr;
	}

	void insert(int key)
	{
		root = insertUtil(root, key);
	}
	void remove(int key)
	{
		root = removeUtil(root, key);
	}
	void print(ofstream& output)
	{
		
		int h = height(root);

		for (int i = 1; i <= h; i++)
		{
			printUtil(root, i, output);
			output << endl;
		}
	}

private:	// fix height function cause of repition...asplhjk;nasdflphjknfasdgpihjkasfdgr;kjbadfgv
	node* root;
	node* insertUtil(node* n, int val)
	{
		// normal BST insertion
		if (n == nullptr)
		{
			cout << "Inserted: " << val << endl;
			node* newNode = new node(val);
			return newNode;
		}
		if (val < n->data)
		{
			n->left = insertUtil(n->left, val);
		}
		else if (val > n->data)
		{
			n->right = insertUtil(n->right, val);
		}
		else
		{
			return n;
		}

		// update height of tree
		int bf = balanceFactor(n);


		if (bf > 1 && val < n->left->data)
		{
			return rightRotate(n);
		}
		else if (bf < -1 && val > n->right->data)
		{
			return leftRotate(n);
		}
		else if (bf > 1 && val > n->left->data)
		{
			n->left = leftRotate(n->left);
			return rightRotate(n);
		}
		else if (bf < -1 && val < n->right->data)
		{
			n->right = rightRotate(n->right);
			return leftRotate(n);
		}

		return n;
	}

	node* removeUtil(node* n, int key)
	{

		// normal BST removal 
		if (n == nullptr)
		{
			return n;
		}

		if (key < n->data)
		{
			n->left = removeUtil(n->left, key);
		}
		else if (key > n->data)
		{
			n->right = removeUtil(n->right, key);
		}
		else
		{
			if (n->left == nullptr || n->right == nullptr)
			{
				node* temp = n->left ? n->left : n->right;

				if (temp == nullptr)
				{
					temp = n;
					n = nullptr;
				}
				else
				{
					*n = *temp;
				}
				free(temp);
			}
			else
			{
				node* temp = findMin(n->right);
				n->data = temp->data;
				n->right = removeUtil(n->right, temp->data);
			}
		}
		if (n == nullptr)
		{
			return n;
		}

		n->height = height(n);

		int bf = balanceFactor(n);

		if (bf > 1 && balanceFactor(root->left) >= 0)
		{
			return rightRotate(n);
		}
		if (bf > 1 && balanceFactor(n->left) < 0)
		{
			n->left = leftRotate(n->left);
			return rightRotate(n);
		}
		if (bf < -1 && balanceFactor(n->right) <= 0)
		{
			return leftRotate(n);
		}
		if (bf < -1 && balanceFactor(n->right) > 0)
		{
			n->right = rightRotate(n->right);
			return leftRotate(n);
		}

		return n;
	}

	node* rightRotate(node* y)
	{
		node* x = y->left;
		node* T2 = x->right;

		// perfrom rotation
		y->left = nullptr;
		x->right = y;
		y->left = T2;

		// update heights
		y->height = height(y);
		x->height = height(x);
		if (T2 != nullptr)
		{
			T2->height = height(T2);
		}

		return y;
	}

	node* leftRotate(node* x)
	{
		node* y = x->right;
		node* T2 = y->left;

		// perform rotation
		x->right = nullptr;
		y->left = x;
		x->right = T2;

		// update heights
		x->height = height(x);
		y->height = height(y);
		if (T2 != nullptr)
		{
			T2->height = height(T2);
		}
		return x;
	}

	int height(node* n)
	{
		if (n == nullptr)
		{
			return 0;
		}

		int right = height(n->right);
		int left = height(n->left);

		if (right > left)
		{
			return right + 1;
		}
		else
		{
			return left + 1;
		}
	}

	int balanceFactor(node* n)
	{
		if (n == nullptr)
		{
			return 0;
		}
		return height(n->left) - height(n->right);
	}

	node* findMin(node* n)
	{
		while (n->left != nullptr)
		{
			n = n->left;
		}
		return n;
	}
	
	void printUtil(node* n, int level, ofstream& output)
	{
		if (n == nullptr)
		{
			return;
		}
		if (level == 1)
		{
			output << n->data << " ";
		}
		else if (level > 1)
		{
			printUtil(n->left, level - 1, output);
			printUtil(n->right, level - 1, output);
		}
	}
};
