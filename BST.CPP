#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	node *left, *right;
}*root;
int rv = 0, n = 0, l = 0;
class BST
{
	public:
		void insert(node *, int);
		void inorder(node *);
		void preorder(node *);
		void postorder(node *);
		void display(node *, int);
		int search(node *, int);
		void delete_node(int);
		BST()
		{
			root = NULL;
		}
};
void main()
{
	clrscr();
	int choice, num , ele;
	BST bst;
	node *temp;
	do
	{
		cout<<"--------------------------------"<<endl;
		cout<<"OPERATIONS ON BINARY SEARCH TREE"<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<"1.INSERT\t";
		cout<<"2.SEARCH\t";
		cout<<"3.DELETE"<<endl;
		cout<<"4.DISPLAY\t";
		cout<<"5.EXIT\t\t";
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:	cout<<"Enter the element to be inserted : ";
				cin>>ele;
				bst.insert(root, ele);
				break;
			case 2:	if (root == NULL)
					cout<<"TREE IS EMPTY...???"<<endl;
				else
				{
					cout<<"Enter the element to be searched : ";
					cin>>ele;
					bst.search(root, ele);
				}
				break;
			case 3:	if (root == NULL)
					cout<<"TREE IS EMPTY...???"<<endl;
				else
				{
					cout<<"Enter the element to be deleted : ";
					cin>>ele;
					bst.delete_node(ele);
				}
				break;
			case 4:	if (root == NULL)
					cout<<"TREE IS EMPTY...???"<<endl;
				else
				{
					bst.display(root,1);cout<<endl;cout<<endl;cout<<n<<" "<<l<<endl;
					cout<<"INORDER : ";bst.inorder(root);cout<<endl;
					cout<<"PREORDER : ";bst.preorder(root);cout<<endl;
					cout<<"POSTORDER : ";bst.postorder(root);cout<<endl;n = l = 0;
				}
				break;
			case 5:	cout<<"SUCCESSFULLY EXITED"<<endl;
				exit(1);
			default:cout<<"WRONG CHOICE...!!!"<<endl;
		}
	}
	while(choice != 5);
	getch();
}
void BST::insert(node *ptr, int value)
{
	if (root == NULL)
	{
		root = new node;
		root->info = value;
		root->left = NULL;
		root->right = NULL;
		cout<<root->info<<" ENTERD AS ROOT"<<endl;
	}
	else if (value < ptr->info)
	{
		rv = ptr->info;
		if (ptr->left != NULL)
		{
			insert(ptr->left, value);
		}
		else
		{
			ptr->left = new node;
			ptr = ptr->left;
			ptr->info = value;
			ptr->left = NULL;
			ptr->right = NULL;
			cout<<ptr->info<<" ENTERED AS LEFT OF "<<rv<<endl;
		}
	}
	else if (value > ptr->info)
	{
		rv = ptr->info;
		if (ptr->right != NULL)
		{
			insert(ptr->right, value);
		}
		else
		{
			ptr->right = new node;
			ptr = ptr->right;
			ptr->info = value;
			ptr->left = NULL;
			ptr->right = NULL;
			cout<<ptr->info<<" ENTERED AS RIGHT OF "<<rv<<endl;
		}
	}
	else if (value == ptr->info)
	{
		if(value == root->info)
			cout<<value<<" ALREADY ENTERED IN ROOT"<<endl;
		else if(value < rv)
			cout<<value<<" ALREADY ENTERED IN LEFT OF "<<rv<<endl;
		else if(value > rv)
			cout<<value<<" ALREADY ENTERED IN RIGHT OF "<<rv<<endl;
	}
}
int BST::search(node *ptr, int value)
{
	node *temp;
	int flag = 0;
	while(ptr != NULL)
	{
		if (value < ptr->info)
		{
			temp = ptr;
			ptr = ptr->left;
		}
		else if (value > ptr->info)
		{
			temp = ptr;
			ptr = ptr->right;
		}
		else if (value == ptr->info)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		if(value == root->info)
		{cout<<value<<" FOUND AT ROOT"<<endl;}
		else if(value < temp->info)
		{cout<<value<<" FOUND AT LEFT OF "<<temp->info<<endl;}
		else if(value > temp->info)
		{cout<<value<<" FOUND AT RIGHT OF "<<temp->info<<endl;}
		return (*temp,value);

	}
	else
		cout<<value<<" NOT FOUND"<<endl;
}
void BST::delete_node(int value)
{
	node *tmt;
	tmt = root;
	search(tmt, value);
	cout<<tmt->info<<value<<endl;
}
void BST::display(node *ptr, int level)
{
	if (ptr != NULL)
	{
		display(ptr->right, level+1);
		cout<<endl;
		if (ptr == root)
			cout<<"ROOT->:  ";
		else
		{
			for (int i = 0;i < level;i++)
				cout<<"          ";
		}
		n++;
		cout<<ptr->info;
		display(ptr->left, level+1);
	}
	l = level;
}
void BST::preorder(node *ptr)
{
	if (ptr != NULL)
	{
		cout<<ptr->info<<" ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
void BST::inorder(node *ptr)
{
	if (ptr != NULL)
    	{
		inorder(ptr->left);
		cout<<ptr->info<<" ";
		inorder(ptr->right);
	}
}
void BST::postorder(node *ptr)
{
	if (ptr != NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout<<ptr->info<<" ";
	}
}