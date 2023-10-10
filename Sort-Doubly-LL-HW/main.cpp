#include <algorithm>
#include "linkedList.h"
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
	string sort;
	// add nums to list and remove unwanted characters
	getline(input, data);
	data.erase(remove(data.begin(), data.end(), '\n'), data.end());
	data.erase(remove(data.begin(), data.end(), '\r'), data.end());
	list.addNums(data);

	// check if input was valid
	if (list.getHead() == nullptr)
	{
		output << "Input is invalid.";
		exit(0);
	}

	//get sorting type
	getline(input, sort);
	sort.erase(remove(sort.begin(), sort.end(), '\n'), sort.end());
	sort.erase(remove(sort.begin(), sort.end(), '\r'), sort.end());

	if (sort == "Selection")
	{
		list.selectionSort(output);
	}
	else if (sort == "Insertion")
	{
		
	}
	else if (sort == "Bubble")
	{
		
	}

	cout << "Finished Program";

	return 0;
}