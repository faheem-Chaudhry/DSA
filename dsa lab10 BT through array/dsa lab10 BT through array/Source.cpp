#include<iostream>
using namespace std;
template<class T>
class BinaryTree
{
private:
	int height; // represent the maximum possible height of the tree.
	T* data; // stores the tree nodes.
	bool* status; // this array is used to find that whether there is a
	// node on a particular index or not. If there is a valid
	// node exitsts on a particular index the status array holds
	// 'true' on corresponding index.

public:
	BinaryTree(int h) //initializes all the data members
	{
		height = h;
		data = new T[pow(2,height)-1];
		status = new bool[pow(2, height) - 1];
	}
//	~BinaryTree();
	void setRoot(T val) // set val at data[0] as a root of tree and set status[0]
	{
		data[0] = val;
		status[0] = true;
	}
	T getRoot()
	{
		return data[0];
	}
	int getRootPosition()
	{
		return 0;
	}
	void setLeftChild(T parent, T val)// sets tge left child of given Parent.
	{
		for (int i = 0; i < pow(2, height) - 1; i++)
		{
			if (status[i] == true && data[i] == parent)
			{
				data[2 * i + 1] = val;
				status[2 * i + 1] = true;
			}
		}
	//	data[2 * parent + 1] = val;
	//	status[2 * parent + 1] = true;

	}
	void setRightChild(T parent, T val)
	{
		//data[2 * parent + 2] = val;
		//status[2 * parent + 2] = true;
		for (int i = 0; i < pow(2, height) - 1; i++)
		{
			if (status[i] == true && data[i] == parent)
			{
				data[2 * i + 2] = val;
				status[2 * i + 2] = true;
			}
		}

	}
	int getParent(int node)
	{
		if (data[0] == data[node])
			return 0;
		int parent = 0;
		 parent = (node - 1) / 2;
		return data[parent];
	
	}
	int getParentNode(int node)
	{
		if (data[0] == data[node])
			return 0;
		int parent = 0;
		parent = (node - 1) / 2;
		return parent;

	}
	T getLeftChild(int par)
	{
		return data[2 * par + 1];
	}
	int PositionLeftChild(int par)
	{
	
		int position = 2 * par + 1;
		if (status[position] == true)
		{
			return position;
		}
		return 0;
	}
	T getRightChild(int par)
	{
		return data[2 * par + 2];
	}
	int PositionRightChild(int par)
	{
		int position = 2 * par + 2;
		return position;
	}
	void Inorder(int val)
	{
		if (val > pow(2, height) - 1)
		{
			return;
		}
		if (height == 0)
			return;
		if (status[val] == true)
			Inorder(val * 2 + 1);
		   
		if (status[val] == true)
		{
			cout << data[val] << endl;
		}
		if (status[val] == true)
			Inorder(val * 2 + 2);
	}
	void Preorder(int val)
	{
		if (val > pow(2, height) - 1)
		{
			return;
		}
		if (height == 0)
			return;
		if (status[val] == true)        //VLR
		{
			cout << data[val] << endl;
		}
		if (status[val] == true)
			Inorder(val * 2 + 1);
		
		if (status[val] == true)
			Inorder(val * 2 + 2);
	}
	void Postorder(int val)
	{
		if (val > pow(2, height) - 1)
		{
			return;
		}
		if (height == 0)
			return;
		if (status[val] == true)
			Inorder(val * 2 + 1);

		if (status[val] == true)
			Inorder(val * 2 + 2);

		if (status[val] == true)
		{
			cout << data[val] << endl;
		}
		
	}
	bool isPerfectTree()
	{
		for (int i = 0; i < pow(2, height) - 1; i++)
		{
			if (status[i] != true)
			{
				return false;
			}
		}
		return true;
	}
	void levelOrder()
	{
		for (int i = 0; i < pow(2, height) - 1; i++)
		{
			if (status[i] == true)
			{
				cout << data[i] << endl;
			}
		}
	}
	void displayAncestors(T node)
	{
	    for (int i = 0; i < pow(2, height) - 1; i++)
		{
			if (data[i] == node )
			{
					displayAncestors(getParent(i));
				cout << getParent(i) << endl;
				
			}
		}
	}
	void displayDescendents(T node)
	{
		for (int i = 0; i < pow(2, height) - 1; i++)
		{
			if (data[i] == node)
			{
				Inorder(i);
			}
		}
	}
	void Delete(int val)
	{
		if (val > pow(2, height) - 1)
		{
			return;
		}
		if (height == 0)
			return;

		if (status[val] == true)
		{
			data[val] = 0;
			status[val] = false;
		}
		if (status[val * 2 + 1] == true)
			Delete(val * 2 + 1);

		
		if (status[val * 2 + 2] == true)
			Delete(val * 2 + 2);
	}
	void remove(T node)
	{
		for (int i = 0; i < pow(2, height) - 1; i++)
		{
			if (data[i] == node)
			{
				Delete(i);
			}
		}
	}
};
int main()
{
	BinaryTree<int> tree(3);
	tree.setRoot(20);
	tree.setLeftChild(20, 11);
	tree.setRightChild(20, 22);
	tree.setLeftChild(11, 9);
	tree.setRightChild(11, 5);
	cout << tree.getParent(1) << endl;
	cout << tree.getParent(2) << endl;
	cout << tree.getRightChild(0) << endl << endl;
	tree.Inorder(tree.getRootPosition());
	cout << endl;
	tree.Preorder(tree.getRootPosition());
	cout << endl;
	tree.Postorder(tree.getRootPosition());
	if (tree.isPerfectTree())
	{
		cout << "Tree is perfect " << endl;
	}
	else
	{
		cout << "Tree is not perfect " << endl;
	}
	cout << "Decestors are : " << endl;
	tree.displayDescendents(11);
	cout << "Level order are : " << endl;
	tree.levelOrder();
	cout << "ancestors are : " << endl;
	tree.displayAncestors(5);
	cout << endl << "After deletion : " << endl;
	tree.remove(11);
	tree.levelOrder();
}