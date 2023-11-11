
struct node
{
	node* left = nullptr;
	int key;
	node* right = nullptr;
};

class BST
{
private:
	node* root;

public:
	BST()
	{
		root = nullptr;
	}
	node* getRoot()
	{
		return root;
	}
	void insert(int val);
	void insertToTree(node* r, int val);
	node* minValueNode(node* r);
	void remove(int val);
	node* remover(node* r, int val);
	bool checkOrder(string nums, ofstream& output);
	void inOrder(node* r);
	void preOrder(node* r);
	void postOrder(node* r);
};
