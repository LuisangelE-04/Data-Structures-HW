#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <sstream>

using namespace std;

struct node
{
	int val;
	node* next = nullptr;
	node* prev = nullptr;
};

class linkedList
{
private:
	node* head;
	int listSize;

public:
	linkedList()
	{
		head = nullptr;
		listSize = 0;
	}

	node* getHead() 
	{ 
		return head;
	}

	int getSize();

	bool isEmpty()
	{
		return head == nullptr;
	}

	void addNums(string data);

	void emptyList();


	void print(ofstream& output);

	node* swapNodes(node* minIndex, node* min);

	void selectionSort(ofstream& output);
};

#endif