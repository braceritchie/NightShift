#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *left,*right;
		bool rightThread, leftThread;
};

class BinaryThreadedSearchTree
{
	private:
		node *root;
	public:
		BinaryThreadedSearchTree()
		{
			root = NULL;	
		}

		void insert(int data)
		{
			node *temp = new node;
			temp->data = data;
			temp->left = NULL;
			temp->right = NULL;
			temp->rightThread = false;
			temp->leftThread = false;
			if(root == NULL)
			{
				root = temp;

			}
			else
			{
				node *trav = root;
				node *curr = root;
				while(trav != NULL)
				{
					curr = trav;
					if(temp->data > trav->data)
					{
						trav = trav->right;
					}
					else
					{
						trav = trav->left;
					}

				}

				if(temp->data > curr->data)
				{
					
					
					temp->right = curr->right;
					
					curr->right = temp;
					
					temp->rightThread = true;
					curr->rightThread = false;
					

					
				}
				else
				{
					
					temp->right = curr;
					
					curr->left = temp;
					
					curr->leftThread = false;
					temp->rightThread = true;
					
				}
					
			}


		}

		void displaySingleThread()
		{
			node *trav = leftmost(root);	
			while(trav != NULL)
			{
				cout<<endl<<trav->data;
				if(trav->rightThread)
				{
					trav = trav->right;
					
				}
				else
				{
					trav = leftmost(trav->right);
			
				}	
			
			}	
		}

		node* leftmost(node *temp)
		{
			node *trav = temp;
			while(trav->left!=NULL)
			{
				trav = trav->left;
			}
			return trav;
		}

		node* getroot()
		{
			return root;
		}
};


int main()
{
	BinaryThreadedSearchTree btree;
	btree.insert(10);
	btree.insert(20);
	btree.insert(9);
	btree.insert(30);
	btree.insert(15);
	btree.displaySingleThread();
	return 0;
}


/*
$ ./BinaryThreadedTree 

9
10
15
20
30

*/
