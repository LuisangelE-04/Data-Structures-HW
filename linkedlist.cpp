#include "linkedlist.h"

void linkedList::addNums(string data)
{
	// check valid input of numbers
	istringstream inSS(data);

	string num;
	bool invalidNum;
	while (inSS >> num)
	{
		invalidNum = false;
		for (int i = 0; i < num.length(); i++)
		{
			if (!isdigit(num[i]))
			{
				invalidNum = true;
				break;
			}
		}
		// state if valid or not
		if (invalidNum)
		{
			// delete previous nodes if added
			linkedList::emptyList();

			break;
		}
		// create node and add to list
		else
		{
			// create node and fill data
			node* temp = new node;
			temp->val = stoi(num);

			// link to list;
			if (head == nullptr)
			{
				head = temp;
				tail = temp;
				
			}
			else
			{
				tail->next = temp;
				temp->prev = tail;
				tail = temp;
				
			}
		}

	}
	// exited while loop
	
}

void linkedList::emptyList()
{
	if (head == nullptr)
	{
		return;
	}

	node* curr = head;
	node* temp;

	while (curr != nullptr)
	{
		temp = curr;
		curr = curr->next;
		delete temp;
	}
	head = nullptr;
}

void linkedList::insertionSort(int s, ofstream& output)
{

}

void linkedList::selectionSort(int s, ofstream& output)
{
	// sorted index
	node* minIndex = head;
	// mark the min node
	node* min = head;
	// traverse list to find min node
	node* curr;
	// poiinter hold
	node* hold;
	// flag if a smaller value is found
	bool flag = false;

	while (minIndex != nullptr)
	{
		curr = minIndex->next;
		// find a new min if available
		while (curr != nullptr)
		{
			// compare values at each node to minIndex
			if (curr->val < minIndex->val)
			{
				// make curr the new min and flag
				min = curr;
				cout << "flagged: " << min->val;
				flag = true;
			}
			curr = curr->next;
		}
		// swap values if a new min is found
		if (flag)
		{
			// if min is less than head value
			if (minIndex->prev == nullptr)
			{
				cout << " at head";
				if (minIndex->next == min)
				{
					cout << " and next to minIndex" << endl;
					minIndex->next = min->next;
					min->next->prev = minIndex;
					
					min->next = minIndex;
					min->prev = minIndex->prev;
					minIndex->prev = min;

					head = min;
				}
				else
				{
					min->prev->next = min->next;
					min->next->prev = min->prev;

					min->next = minIndex;
					min->prev = minIndex->prev;
					minIndex->prev = min;

					head = min;
				}
			}
			//if min appears right after minIndex
			else if (minIndex->next == min)
			{
				// unlink min from current position
				min->prev->next = min->next;
				min->next->prev = min->prev;

				hold = minIndex->prev->next;
				// insert min before minIndex
				minIndex->prev->next = min;
				min->prev = minIndex->prev;
				
				min->next = hold;
				hold->prev = min;
			}
			

		}
		// end while loop
		// print after every sort iteration
		linkedList::print(output);
		cout << endl;
		minIndex = minIndex->next;
		flag = false;
	}
}

void linkedList::bubbleSort(int s, ofstream& output)
{
	
}

int linkedList::getSize()
{
	node* curr = head;

	if (curr == nullptr)
	{
		return 0;
	}
	while (curr != nullptr)
	{
		listSize++;
		curr = curr->next;
	}

	return listSize;
}

void linkedList::print(ofstream& output)
{
	if (head == nullptr)
	{
		return;
	}
	
	node* curr = head;
	cout << "[";
	while (curr->next != nullptr)
	{
		cout << curr->val << ",";
		curr = curr->next;
	}
	cout << curr->val << "]";
}