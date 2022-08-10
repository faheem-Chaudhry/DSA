#include<iostream>
using namespace std;
template<class T>
class BSTNode
{
public:
	int data;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int val)
	{
		data = val;
		left = right = NULL;
	}
};
template<class T>
class BST
{
	BSTNode<T>* root;
public:
	BSTNode<T>* getRoot()
	{
		return root;
	}
	BST()
	{
		root = NULL;
	}
	BST(const BST& obj)
	{
		root->left = obj.root->left;
		root->right = obj.root->right;
		root->data = obj.root->data;
	}

	void setRoot(int val)
	{
		root = new BSTNode<T>(val);
	}
	BSTNode<T>* getLeftChild(BSTNode<T>* node)
	{
		return node->left;
	}
	BSTNode<T>* getRightChild(BSTNode<T>* node)
	{
		return node->right;
	}
	void insert(int val)
	{
		if (!root)	// when tree is empty
			setRoot(val);
		else
		{
			BSTNode<T>* temp = root;
			BSTNode<T>* prev = temp;
			while (temp)
			{
				if (temp->data > val)
				{
					prev = temp;
					temp = temp->left;
				}
				else
				{
					prev = temp;
					temp = temp->right;
				}
			}
			if (prev->data > val)
				prev->left = new BSTNode<T>(val);
			else
				prev->right = new BSTNode<T>(val);
		}
	}
	bool search(int val)
	{
		BSTNode<T>* temp = root;
		while (temp)
		{
			if (temp->data == val)
				return true;
			else
			{
				if (temp->data > val)
					temp = temp->left;
				else
					temp = temp->right;
			}
		}
		return false;
	}

	BSTNode<T>* getNode(int val)
	{
		BSTNode<T>* temp = root;
		while (temp)
		{
			if (temp->data == val)
				return temp;
			else
			{
				if (temp->data > val)
					temp = temp->left;
				else
					temp = temp->right;
			}
		}
		return NULL;
	}
	void inOrder(BSTNode<T>* root)
	{
		if (!root)
			return;
		inOrder(root->left);
		cout << root->data << endl;
		inOrder(root->right);
	}
	void deleteNode(int val)
	{
		BSTNode<T>* toDelete = getNode(val);
		if (toDelete->left == NULL && toDelete->right == NULL)	// case 1
		{
			BSTNode<T>* temp = root;
			while (temp)
			{
				if (temp->right->data == val)
				{
					temp->right = NULL;
					delete toDelete;
					return;
				}
				else if (temp->left->data == val)
				{
					temp->left = NULL;
					delete toDelete;
					return;
				}
				else
				{
					if (temp->data > val)
						temp = temp->left;
					else
						temp = temp->right;
				}
			}
		}
		else if (toDelete->left != NULL && toDelete->right != NULL) // case 3
		{
			int swap = 0;
			BSTNode<T>* temp = toDelete->right;
			while (temp)
			{

				if (toDelete->right->left == NULL)
				{
					temp = temp->right;
				}
				if (temp->left == NULL)
				{
					swap = temp->data;
					temp->data = toDelete->data;
					toDelete->data = swap;
				}
				temp = temp->left;
			}
			
		}
		else // case 2
		{
			BSTNode<T>* temp = root;
			while (temp)
			{
				if (temp->right->data == val)
				{
					if (toDelete->right != NULL)
					{
						temp->right = toDelete->right;
						delete toDelete;
						return;
					}
					else
					{
						temp->right = toDelete->left;
						delete toDelete;
						return;
					}
				//	temp->right = NULL;
				//	delete toDelete;
				//	return;
				}
				else if (temp->left->data == val)
				{
					if (toDelete->right != NULL)
					{
						temp->left = toDelete->right;
						delete toDelete;
						return;
					}
					else
					{
						temp->left = toDelete->left;
						delete toDelete;
						return;
					}
				
				}
				else
				{
					if (temp->data > val)
						temp = temp->left;
					else
						temp = temp->right;
				}
			}
		}
	}
	bool isInternalNode(BSTNode<T>* node)
	{
		if (node->right == NULL && node->left == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	bool isExternalNode(BSTNode<T>* node)
	{
		if (node->right == NULL && node->left == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int getHeight(BSTNode<T>* root)
	{
		if (root == NULL)
			return 0;
		else
		{
		//	BSTNode* temp = root;
			int lheight = getHeight(root->left);
			int rheight = getHeight(root->right);

			/* use the larger one */
			if (lheight > rheight)
			{
				return(lheight + 1);
			}
			else {
				return(rheight + 1);
			}
		}
	
	}
	void displayAncestors(int val)
	{
		BSTNode<T>* temp = root;
	//	cout << root->data << endl;
		BSTNode<T>* ancestor = getNode(val);
		while (temp)
		{
			if (temp->right == ancestor)
			{
				cout << temp->data << endl;
				break;
			}
			else if (temp->left == ancestor)
			{
				cout << temp->data << endl;
				break;
			}
			else
			{
				if (temp->data > val)
				{
					cout << temp->data << endl;
					temp = temp->left;
				}
				else
				{
					cout << temp->data << endl;
					temp = temp->right;
				}
			}
		}

	}
	void displayDescedents(int val)
	{
		BSTNode<T>* temp = getNode(val);

		inOrder(temp->left);
		if (temp->data != val)
		{
			cout << temp->data << endl;
		}
		inOrder(temp->right);
		
	}	
	bool isBST(BSTNode<T>* root)               //bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
	{

	}
	void printinLevelOrder()
	{
		int counter = 0;
		int counter2 = 0;
		BSTNode* temp = root;
		BSTNode* prev = temp;
		cout << root->data << " "<< endl;
		int h;
			while (temp, h = getHeight(temp))
		{
		//	prev = temp;
			if (temp->left)
			{
				cout <<temp->left->data << "  ";
			}
			if (temp->right)
			{
				cout << temp->right->data << "  ";
			}
			if (counter == 1)
			{
				temp = prev->right;
				counter2 = 1;

			}
			if (counter == 0)
			{
				temp = prev->left;
				counter = 1;
			}
			if (counter2 == 1)
			{
				prev = prev->left;
				counter = 0;
				counter2 = 0;
			}

		}
	}
	int getNodeCount(BSTNode<T>* root)
	{
		if (!root)
			return 0;
	//	cout << "pak";
	//	tree.getRoot();
		static int counter = 0;
	//	BSTNode* temp = tree.getRoot();
		getNodeCount(root->left);
		counter++;
		getNodeCount(root->right);
		return counter;
	}

	bool isEqual(BSTNode<T>* r1, BSTNode<T>* r2)
	{
		static int counter = 0;
		if (r1 == NULL )
		{
			if (r2 == NULL)
			{
				return true;
			}
		}			
		if ((!r1 && r2) || (r1 && !r2))
			return false;
//		static int counter = 0;
		if (r1->data != r2->data)
		{
			cout << r1->data << " " << r2->data;
			return false;
		//	counter++;
		}
		isEqual(r1->left, r1->left);
		isEqual(r1->right, r2->right);
		
		//counter++;  
		
	}
	int findMin()
	{
		BSTNode<T>* temp = root;
		BSTNode<T>* temp2 = NULL;
		while (temp)
		{
		    temp2 = temp;
			temp = temp->left;
		}
		return temp2->data;
	}
	int findMax()
	{
		BSTNode<T>* temp = root;
		BSTNode<T>* temp2 = NULL;
		while (temp)
		{
			temp2 = temp;
			temp = temp->right;
		}
		return temp2->data;
	}
};

int main()
{
	BST<int> tree;
	BST<int> tree2;

	tree.insert(20);
	tree.insert(22);
	tree.insert(65);
	tree.insert(60);
	tree.insert(25);
	tree.insert(32);
	tree.insert(43);
	tree.insert(11);
	tree.insert(9);
	tree.insert(70);
	tree.insert(46);
	tree.insert(21);
	tree.insert(15);


	tree2.insert(20);
	tree2.insert(22);
	tree2.insert(65);
	tree2.insert(60);
	tree2.insert(25);
	tree2.insert(32);
	tree2.insert(43);
	tree2.insert(11);
	tree2.insert(9);
	tree2.insert(70);
	tree2.insert(46);
	tree2.insert(21);
	tree2.insert(15);

	tree.inOrder(tree.getRoot());
//	tree.deleteNode(22);
//	tree.printTree();
	cout << endl;
//	tree.inOrder(tree.getRoot());
	if (tree.isInternalNode(tree.getNode(25)))
	{
		cout << "Given node is internal node" << endl;
	}
	else
	{
		cout << "Given node is not internal node" << endl;
	}
	if (tree.isExternalNode(tree.getNode(70)))
	{
		cout << "Given node is external node" << endl;
	}
	else
	{
		cout << "Given node is not external node" << endl;
	}
	tree.displayAncestors(46);  //it return data in inorder form of their descends
	cout << " Total nodes = " << tree.getNodeCount(tree.getRoot()) << endl;

	cout << "Height of tree is = " << tree.getHeight(tree.getRoot()) << endl;
	if (tree.isEqual(tree.getRoot(), tree2.getRoot()))
	{
		cout << "Both trees are equal" << endl;
	}
	else
	{
		cout << "Both trees are not equal" << endl;
	}
	cout << "minimum value in tree is : " << tree.findMin() << endl;
	cout << "maximum value in tree is : " << tree.findMax();
}