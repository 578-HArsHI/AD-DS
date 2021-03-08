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
		void search(int, node **, node **);
		void delete_node(int);
		void case_a(node *,node *);
		void case_b(node *,node *);
		void case_c(node *,node *);
		void display(node *, int);
		void preorder(node *);
		void inorder(node *);
		void postorder(node *);
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
	node *temp1, *temp2;
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
					bst.search(ele,&temp1,&temp2);
					if(temp2->info == 0)
						cout<<ele<<" NOT FOUND"<<endl;
					else if(temp2->info == root->info)
						cout<<temp2->info<<" FOUND AT ROOT"<<temp1->info<<endl;
					else if(temp2->info < temp1->info)
						cout<<temp2->info<<" FOUND AT LEFT OF "<<temp1->info<<endl;
					else if(temp2->info > temp1->info)
						cout<<temp2->info<<" FOUND AT RIGHT OF "<<temp1->info<<endl;
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
					bst.display(root,1);cout<<endl;cout<<endl;
					cout<<"NUMBER OF NODES : "<<n<<"\t LEVEL : "<<l<<endl;
					cout<<"PREORDER : ";bst.preorder(root);cout<<endl;
					cout<<"INORDER : ";bst.inorder(root);cout<<endl;
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
void BST::search(int item, node **par, node **loc)
{
	node *ptr1 = root, *ptr2 = root;
	while (ptr1 != NULL)
	{
		if (item == root->info)
		{
			*loc = root;
			*par = NULL;
			return;
		}
		else if (item == ptr1->info)
		{
			*loc = ptr1;
			*par = ptr2;
			return;
		}
		ptr2 = ptr1;
		if (item < ptr1->info)
			ptr1 = ptr1->left;
		else
			ptr1 = ptr1->right;
	}
	*loc = NULL;
	*par = ptr2;
}
void BST::delete_node(int item)
{
	node *parent, *location;
	search(item,&parent,&location);
	if (location == NULL)
		cout<<"NOT FOUND"<<endl;
	else if (location->left == NULL && location->right == NULL)
		case_a(parent, location);
	else if (location->left != NULL && location->right != NULL)
		case_c(parent, location);
	else
		case_b(parent, location);
	free(location);
}
void BST::case_a(node *par, node *loc )
{
	if (par == NULL)
		root = NULL;
	else
	{
		if (loc == par->left)
			par->left = NULL;
		else
			par->right = NULL;
	}
}
void BST::case_b(node *par, node *loc)
{
	node *child;
	if (loc->left != NULL)
		child = loc->left;
	else
		child = loc->right;
	if (par == NULL)
		root = child;
	else
	{
		if (loc == par->left)
			par->left = child;
		else
			par->right = child;
	}
}
void BST::case_c(node *par, node *loc)
{
	node *ptr, *ptrsave, *suc, *parsuc;
	int op = 0;
	ptrsave = loc;
	cout<<"1.LEFTMOST OF RIGHT\t";
	cout<<"2.RIGHTMOST OF LEFT\t";
	cout<<"Enter your choice : ";
	cin>>op;
	if (op == 1)
	{
		ptr = loc->right;
		while (ptr->left != NULL)
		{
			ptrsave = ptr;
			ptr = ptr->left;
		}
	}
	else if(op == 2)
	{
		ptr = loc->left;
		while (ptr->right != NULL)
		{
			ptrsave = ptr;
			ptr = ptr->right;
		}
	}
	else
	{
		cout<<"WRONG CHOICE...TRY AGAIN"<<endl;
		return;
	}
	suc = ptr;
	parsuc = ptrsave;
	if (suc->left == NULL && suc->right == NULL)
		case_a(parsuc, suc);
	else
		case_b(parsuc, suc);
	if (par == NULL)
		root = suc;
	else
	{
		if (loc == par->left)
			par->left = suc;
		else
			par->right = suc;
	}
	suc->left = loc->left;
	suc->right = loc->right;
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
		}n++;
		cout<<ptr->info;
		display(ptr->left, level+1);
	}
	if (l < level)
		l = level - 1;
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