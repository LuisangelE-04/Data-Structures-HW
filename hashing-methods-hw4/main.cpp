#include "ArgumentManager.h"
#include "hash.h"

int main(int argc, char* argv[])
{
	ArgumentManager am(argc, argv);
	ifstream input(am.get("input"));
	ofstream output(am.get("output"));

	//ifstream input("input1.txt");
	//ofstream output("ans.txt");
	// ALL INPUTS ARE IN CORRECT FORMAT
	// line 1 is size of hash table
	int size;
	input >> size;
	hashTable hash(size);
	
	// line 2 is type of probing
	string hashMethod;

	getline(input, hashMethod);
	getline(input, hashMethod);
	hashMethod.erase(remove(hashMethod.begin(), hashMethod.end(), '\n'), hashMethod.end());
	hashMethod.erase(remove(hashMethod.begin(), hashMethod.end(), '\r'), hashMethod.end());

	// line 3 is integers seperated by commas
	string variables;
	input >> variables;
	stringstream ss(variables);
	int num;

	while (ss >> num)
	{
		if (ss.peek() == ',')
		{
			ss.ignore();
		}
		// add numbers
		hash.insert(num, hashMethod);
	}
	// output array
	hash.print(output);

	// output min heap array
	for (int i = 0; i < size / 2; i++)
	{
		hash.buildMinHeap();
	}
	output << endl;
	hash.print(output);

	return 0;
}
