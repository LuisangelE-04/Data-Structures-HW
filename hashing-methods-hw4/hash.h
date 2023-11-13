#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

class hashTable
{
private:
	int size;
	int* table;
public:
	hashTable(int size)
	{
		this->size = size;
		table = new int[size];
		// initialize each value in array to negative -1
		for (int i = 0; i < size; i++)
		{
			table[i] = -1;
		}
	}

	void insert(int key, string hashMethod)
	{
		// determine which probing method to use
		if (hashMethod == "Linear probing")
		{
			linearProbe(key);
		}
		else if (hashMethod == "Quadratic probing")
		{
			quadraticProbe(key);
		}
	}
	void linearProbe(int key)
	{
		int index = key % size;
		int c1 = 1;
		while (table[index] != -1)
		{
			index = (index + c1) % size;	// linear probe method
		}
		table[index] = key;
	}
	void quadraticProbe(int key)
	{
		int index = key % size;
		int i = 0;
		int c1 = 3;
		int c2 = 5;
		while (table[index] != -1)
		{
			i++;
			index = ((key % size) + c1 * i + c2 * i * i) % size;	// quadratic probe method
		}
		table[index] = key;
	}
	int search(int key, string method)
	{
		int hash = key % size;
		if (method == "Linear probing")
		{
			int c1 = 1;
			while (table[hash] != -1)
			{
				hash = (hash + c1) % size;
			}
			if (table[hash] == -1)
			{
				return -1;
			}
			else
			{
				return table[hash];
			}
		}
		else if (method == "Quadratic probing")
		{
			int i = 0;
			int c1 = 3;
			int c2 = 5;
			while (table[hash] != -1)
			{
				i++;
				hash = ((key % size) + c1 * i + c2 * i * i) % size;
			}
			if (table[hash] == -1)
			{
				return -1;
			}
			else
			{
				return table[hash];
			}
		}
	}
	void print(ofstream& output)
	{
		for (int i = 0; i < size - 1; i++)
		{
			output << table[i] << ",";
		}
		output << table[size - 1];
	}
	void buildMinHeap()
	{
		int startIndex = (size / 2) - 1;

		// heapify each node
		for (int i = startIndex; i >= 0; i--)
		{
			heapifyMin(table, i);
		}
	}
	void heapifyMin(int* arr, int i)
	{
		int smallest = i;		// initialize smallest as root
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		// if left child is smaller than smallest so far
		if (left < size && arr[left] < arr[smallest])
		{
			smallest = left;
		}

		// if right child is smaller than smallest so far
		if (right < size && arr[right] < arr[smallest])
		{
			smallest = right;
		}

		// if smallest is not the root
		if (smallest != i)
		{
			swap(&arr[i], &arr[smallest]);

			// recursively heapify
			heapifyMin(arr, i);
		}
	}
	void swap(int* x, int* y)
	{
		int temp = *x;
		*x = *y;
		*y = temp;
	}
};
