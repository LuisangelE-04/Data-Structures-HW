#include <algorithm>
#include "linkedlist.h"
#include "ArgumentManager.h"


int main(int argc, char* argv[])
{
	ArgumentManager am(argc, argv);
	//ifstream input(am.get("input"));
	//ofstream output(am.get("output"));

	ifstream input("input1.txt");
	ofstream output("ans.txt");

	linkedList list;
	
	string data;
	// add nums to list if valid
	getline(input, data);
	data.erase(remove(data.begin(), data.end(), '\n'), data.end());
	data.erase(remove(data.begin(), data.end(), '\r'), data.end());
	list.addNums(data);

	// if invalid stop program
	if (list.getHead() == nullptr)
	{
		output << "Input is invalid.";
		exit(0);
	}
	// determine sorting algorithm to use
	string sort;
	getline(input, sort);
	sort.erase(remove(sort.begin(), sort.end(), '\n'), sort.end());
	sort.erase(remove(sort.begin(), sort.end(), '\r'), sort.end());

	// get size of the list
	int s = list.getSize();

	// if statements to chose algorithm
	if (sort == "Selection")
	{
		list.selectionSort(s, output);
	}
	else if (sort == "Insertion")
	{
		list.insertionSort(s, output);
	}
	else if (sort == "Bubble")
	{
		list.bubbleSort(s, output);
	}

	return 0;
}