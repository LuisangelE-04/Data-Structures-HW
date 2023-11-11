#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct node
{
	node* left = nullptr;
	int key;
	node* right = nullptr;
};

class BST
{
private:
	node* root;
	int size;

public:
	BST()
	{
		root = nullptr;
		size = 0;
	}
	node* getRoot()
	{
		return root;
	}
	void insert(int val);
	void insertToTree(node* r, int val);
	node* minValueNode(node* r);
	void remove(int val);
	node* remover(node* r, int val);
	void checkOrder(string nums, ofstream& output);
	bool inOrder(node* r, int arr[], int& i);
	bool preOrder(node* r, int arr[], int& i);
	bool postOrder(node* r, int arr[], int& i);
};
