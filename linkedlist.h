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
	node* tail;
	int listSize;

public:
	linkedList()
	{
		head = nullptr;
		tail = nullptr;
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

	void insertionSort(int s, ofstream& output);

	void selectionSort(int s, ofstream& output);

	void bubbleSort(int s, ofstream& output);

	void print(ofstream& output);
};

#endif