#include "AVL.h"
#include "ArgumentManager.h"

int main(int argc, char* argv[])
{
	ArgumentManager am(argc, argv);
	//ifstream input(am.get("input"));
	//ofstream output(am.get("output"));

	ifstream input("input9.txt");
	ofstream output("ans.txt");

	AVL tree;

	string line;
	int num;

	// inert and remove values
	while (getline(input, line))
	{
		num = stoi(line.substr(line.find('(') + 1, line.find(')') - line.find('(') - 1));
		if (line[0] == 'I')
		{
			tree.insert(num);
		}
		else if (line[0] == 'R')
		{
			tree.remove(num);
		}
	}

	// print in level order
	tree.print(output);

	// Finished Program
	cout << "Finished Program";

	return 0;
}
