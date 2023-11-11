#include "binarySearchTree.h"
#include "ArgumentManager.h"
#include <algorithm>

int main(int argc, char* argv[])
{
	ArgumentManager am(argc, argv);
	//ifstream input(am.get("input"));
	//ofstream output(am.get("output"));

	ifstream input("input2.txt");
	ofstream output("ans.txt");

	BST tree;

	string command;
	string nums;
	int val;
	
	while (getline(input, command))
	{
		command.erase(remove(command.begin(), command.end(), '\n'), command.end());
		command.erase(remove(command.begin(), command.end(), '\r'), command.end());

		if (command == "Insert")
		{
			cout << "Inputting numbers: ";
			getline(input, nums);
			istringstream inSS(nums);
			while (inSS >> nums)
			{
				val = stoi(nums);
				tree.insert(val);
				cout << val << " ";
			}
			cout << endl;
		}
		else if (command == "Remove")
		{
			cout << "Removing number/s: ";
			getline(input, nums);
			istringstream inSS(nums);
			while (inSS >> nums)
			{
				val = stoi(nums);
				cout << val << " " << endl;
				tree.remove(val);
			}
		}
		else if (command == "Traverse")
		{
			cout << "Checking traversal." << endl;
			getline(input, nums);
			tree.checkOrder(nums, output);
		}
	}

	// test output

	return 0;
}
