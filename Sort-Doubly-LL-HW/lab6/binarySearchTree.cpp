#include "binarySearchTree.h"
#include <vector>

node* BST::minValueNode(node* r)
{
	node* curr = r;
	while (curr->left != nullptr)
	{
		curr = curr->left;
	}
	return curr;
}

void BST::insert(int val)
{
	BST::insertToTree(root, val);
}

void BST::insertToTree(node* r, int val)
{
	node* newNode = new node;
	newNode->key = val;
	if (root == nullptr)
	{
		root = newNode;
		size++;
		return;
	}

	node* curr = root;
	node* parent = nullptr;
	while (curr != nullptr)
	{
		parent = curr;
		if (curr->key == val)
		{
			return;
		}
		else if (curr->key < val)
		{
			curr = curr->right;
		}
		else if (curr->key > val)
		{
			curr = curr->left;
		}
	}

	if (parent->key < val)
	{
		size++;
		parent->right = newNode;
	}
	else if (parent->key > val)
	{
		size++;
		parent->left = newNode;
	}
}

void BST::remove(int val)
{
	BST::remover(root, val);
}

node* BST::remover(node* r, int val)
{
	if (r == nullptr)
	{
		return r;
	}

	if (val < r->key)
	{
		r->left = remover(r->left, val);
	}
	else if (val > r->key)
	{
		r->right = remover(r->right, val);
	}
	else
	{
		if (r->left == nullptr)
		{
			node* temp = r->right;
			cout << "Deleted: " << r->key << endl;
			delete r;
			size--;
			return temp;
		}
		else if (r->right == nullptr)
		{
			node* temp = r->left;
			cout << "Deleted: " << r->key << endl;
			delete r;
			size--;
			return temp;
		}

		node* temp = minValueNode(r->right);

		r->key = temp->key;

		r->right = remover(r->right, temp->key);
	}
	root = r;
	return r;
}

bool BST::inOrder(node* r, int arr[], int& i)
{
	if (r == nullptr)
	{
		return true;
	}
	inOrder(r->left, arr, i);
	if (r->key != arr[i])
	{
		return false;
	}
	i++;
	inOrder(r->right, arr, i);
}

bool BST::postOrder(node* r, int arr[], int& i)
{
	if (r == nullptr)
	{
		return true;
	}
	if (r->key != arr[i])
	{
		return false;
	}
	preOrder(r->left, arr, i);
	preOrder(r->right, arr, i);
}

bool BST::preOrder(node* r, int arr[], int& i)
{
	if (r == nullptr)
	{
		return true;
	}
	preOrder(r->left, arr, i);
	preOrder(r->right, arr, i);
	if (r->key != arr[i])
	{
		return false;
	}
}

void BST::checkOrder(string nums, ofstream& output)
{
	istringstream inSS(nums);
	vector<int> values;
	int val;
	bool traversal = true;
	while (inSS >> val)
	{
		values.push_back(val);
	}
	// check for empty tree first	
	if (size != values.size())
	{
		output << "False";
		return;
	}
	int index = 0;
	if (BST::inOrder(root, values.data(), index))
	{
		output << "Inorder" << endl;
		
	}
	index = 0;
	if (BST::preOrder(root, values.data(), index))
	{
		output << "Preorder" << endl;
	}
	index = 0;
	if (BST::postOrder(root, values.data(), index))
	{
		output << "Postorder" << endl;
	}
	index = 0;
	if (!BST::inOrder(root, values.data(), index))
	{
		traversal = false;
	}
	
	values.clear();
}
