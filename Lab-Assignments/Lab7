#include <iostream>
#include <vector>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

class Graph
{
private:
	// vector of vectors
	vector<vector<int>> adjList;

	// vectors to check path
	vector<bool> currPath;
	vector<bool> visited;

	// recursive call to check for cycle
	bool isCyclicUtil(int n)
	{
		visited[n] = true;
		currPath[n] = true;
		for (int i = 0; i < adjList[n].size(); i++)
		{
			int link = adjList[n][i];
			if (visited[link] && currPath[link])
			{
				return true;
			}
			if (!visited[link] && isCyclicUtil(link))
			{
				return true;
			}
		}
		currPath[n] = false;
		return false;
	}
public:
	// Graph constructor
	Graph(int numNodes) : adjList(numNodes), visited(numNodes, false), currPath(numNodes, false) {}

	// insert edge
	void insertEdge(int n, int val)
	{
		adjList[n].push_back(val);
	}

	// public call for cycle to keep it simple
	bool isCycle()
	{
		for (int i = 0; i < adjList.size(); i++)
		{
			if (!visited[i] && isCyclicUtil(i))
			{
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char* argv[])
{
	ArgumentManager am(argc, argv);
	ifstream input(am.get("input"));
	ofstream output(am.get("output"));

	//ifstream input("input1.txt");
	//ofstream output("ans.txt");

	// total nodes in graph, the node to be at, and value to connect to that node
	int numNodes, node, val;
	input >> numNodes;

	// create graph 
	Graph graph(numNodes);
	
	// add edges
	while (input >> node >> val)
	{
		graph.insertEdge(node, val);
	}

	// check for cycle and output accordinly
	if (graph.isCycle())
	{
		output << "TRUE";
	}
	else if (!graph.isCycle())
	{
		output << "FALSE";
	}

	return 0;
}
