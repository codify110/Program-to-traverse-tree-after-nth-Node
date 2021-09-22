#include <iostream>
using namespace std;
struct bst
{
	int data;
	bst *left;
	bst *right;
};
bst *Findmin(bst *);
bst *root = NULL;
void insert()
{
	cout << "Enter node data " << endl;
	bst *newnode = new bst;
	cin >> newnode->data;
	newnode->left = newnode->right = NULL;
	if (root == NULL)
	{
		root = newnode;
	}
	else
	{
		bst *temp = root;
		while (temp != NULL)
		{
			if (newnode->data < temp->data)
			{
				if (temp->left == NULL)
				{
					temp->left = newnode;
					break;
				}
				else
				{
					temp = temp->left; // left aur neechay jao 

				}

			}
			else if (newnode->data > temp->data)
			{
				if (temp->right == NULL)
				{
					temp->right = newnode;
					break;
				}
				else
				{
					temp = temp->right; // right aur neechay jao 

				}

			}
			else
			{
				cout << "DUPLICATE DATA " << endl;
				break;
			}

		}
	}
}
void show(bst *temp,int x)
{
	if (temp == NULL)
	{
		return;
	}
	else

	{// inorder// preorder : 2,1,3  //post: 1,3,2 
		show(temp->left,x);
		if (x < temp->data)
		{
			cout << temp->data << " ";
    	}       
        show(temp->right,x);                    
	}

}
int main()
{
	int x, y;
	cout << "How many nodes :" << endl;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		insert();
	}
	cout << "After which node you want to traverse:" << endl;
	cin >> y;
	show(root,y);
	system("pause");

}


