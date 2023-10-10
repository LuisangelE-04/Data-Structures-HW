#include "linkedList.h"

int linkedList::getSize()
{
	node* curr = head;

	if (curr == nullptr)
	{
		return listSize;
	}
	while (curr != nullptr)
	{
		listSize++;
		curr = curr->next;
	}

	return listSize;
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

void linkedList::addNums(string data)
{
	istringstream inSS(data);

	string num;
	bool invalidNum = false;

	while (inSS >> num)
	{
		for (int i = 0; i < num.length(); i++)
		{
			if (!isdigit(num[i]))
			{
				invalidNum = true;
				break;
			}
		}
		// exit number check

		if (invalidNum)
		{
			linkedList::emptyList();
			break;
		}
		else
		{
			node* temp = new node;
			temp->val = stoi(num);

			// link to list
			if (head == nullptr)
			{
				head = temp;
			}
			else
			{
				// traverse to end of list
				node* curr = head;
				while (curr->next != nullptr)
				{
					curr = curr->next;
				}
				// curr is equal to last node of list
				curr->next = temp;
				temp->prev = curr;
			}
			// added to list
		}
	}
	// exit while loop
}

node* linkedList::swapNodes(node* minIndex, node* min)
{
	// if minIndex is at the head and min is at the end of list
	if (minIndex == head && min->next == nullptr)
	{
		//cout << "Swapping " << minIndex->val << " and " << min->val << endl;

		minIndex->prev = min->prev;
		min->prev->next = minIndex;
		min->prev = nullptr;
		minIndex->next->prev = min;
		min->next = minIndex->next;
		minIndex->next = nullptr;
		head = min;
		
		node* newIndex = min;
		return min;
	}
	// if minIndex is at the head and min is next to it
	if (minIndex == head && minIndex->next == min)
	{
		//cout << "Swapping " << minIndex->val << " and " << min->val << endl;

		minIndex->prev = min;
		min->prev = nullptr;
		min->next->prev = minIndex;
		minIndex->next = min->next;
		min->next = minIndex;
		head = min;

		node* newIndex = min;
		return min;
	}
	// if minIndex is at head and min is anywhere else in the list
	if (minIndex == head && min->next != nullptr)
	{
		//cout << "Swapping " << minIndex->val << " and " << min->val << endl;

		//hold for swap
		node* hold;

		minIndex->prev = min->prev;
		min->prev->next = minIndex;
		min->prev = nullptr;
		min->next->prev = minIndex;
		hold = min->next;
		min->next = minIndex->next;
		minIndex->next->prev = min;
		minIndex->next = hold;
		head = min;

		node* newIndex = min;
		return min;
	}
	// if elements are next to each other not at the head
	if(minIndex->next == min && min->next != nullptr)
	{
		cout << "Swapping " << minIndex->val << " and " << min->val << endl;

		minIndex->prev->next = min;
		min->next->prev = minIndex;
		min->prev = minIndex->prev;
		minIndex->next = min->next;
		min->next = minIndex;
		minIndex->prev = min;

		node* newIndex = min;
		return min;
	}
	// if min is the last element and minIndex is not at the head
	if (min->next == nullptr && minIndex != head)
	{
		//cout << "Swapping " << minIndex->val << " and " << min->val << endl;

		// hold for swap
		node* hold;

		min->next = minIndex->next;
		min->prev->next = minIndex;
		minIndex->next->prev = min;
		minIndex->prev->next = min;

		hold = minIndex->prev;
		minIndex->prev = min->prev;
		min->prev = hold;
		minIndex->next = nullptr;

		node* newIndex = min;
		return min;

	}
	// if elements are apart from each other and not at head or last element
	if(min->next != nullptr && minIndex != head) 
	{
		//cout << "Swapping " << minIndex->val << " and " << min->val << endl;

		node* holdP;
		node* holdN;

		minIndex->prev->next = min;
		minIndex->next->prev = min;
		min->prev->next = minIndex;
		min->next->prev = minIndex;

		holdP = minIndex->prev;
		minIndex->prev = min->prev;
		holdN = minIndex->next;
		minIndex->next = min->next;

		min->prev = holdP;
		min->next = holdN;

		node* newIndex = min;

		return min;
	}
}

void linkedList::print(ofstream& output)
{
	// empty list prints out nothing
	if (head == nullptr)
	{
		return;
	}

	// traverse and print in format [1,2,3]
	node* curr = head;
	
	output << "[";
	while (curr->next != nullptr)	// print node before last node to avoid a [1,2,3,]
	{
		output << curr->val << ",";
		curr = curr->next;
	}
	output << curr->val << "]";
}

void linkedList::selectionSort(ofstream& output)
{
	// sorted index
	node* minIndex = head;
	// mark min node
	node* min = head;
	// traverse list
	node* curr;

	// if a smaller value exists
	bool flag = false;

	// traverse with minIndex
	while (minIndex->next != nullptr)
	{
		curr = minIndex->next;
		min = minIndex;
		// traverse remaining elements in list and look for a new min
		while (curr != nullptr)
		{
			// compare values
			if (min->val > curr->val)
			{
				//cout << "Min value is: " << curr->val << endl;
				min = curr;
				flag = true;
			}
			// move to next node
			curr = curr->next;
		}
		// exit inner loop to find new min

		// swap values if new min is found
		if (flag)
		{
			// call swap function
			minIndex = linkedList::swapNodes(minIndex, min);

		}
		// finish iteration of sort and print
		linkedList::print(output);
		output << endl;
		// change minIndex and set flag to false;
		minIndex = minIndex->next;
		flag = false;
	}
	// minIndex is done traversing
}