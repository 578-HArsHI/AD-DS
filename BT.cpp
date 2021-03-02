#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream.h>
#include<iomanip.h>

 struct tree {
 int info;
 struct tree *left;
 struct tree *right;
 }*parent = NULL;

class BST
{
 struct tree *root;
 int choice, item,item_no;
  public:
	BST(){ root = NULL;}
	struct tree *create(struct tree *,int);
 	struct tree *insert(struct tree *,int);
	struct tree *delet(struct tree *,int);
 	void inorder(struct tree *);
 	void postorder(struct tree *);
 	void preorder(struct tree *);
 	void inorder1(struct tree *);
	struct tree *search(struct tree *);	
	void menu();
};

void BST::menu(){
do {
 do { 
 cout<<"\n \t 0. create Binary Tree ";
 cout<<"\n \t 1. Insert in Binary Tree ";
 cout<<"\n\t 2. Inorder traversal of Binary tree";
 cout<<"\n\t 3. Postorder traversal of Binary tree";
 cout<<"\n\t 4. Preorder traversal of Binary tree";
 cout<<"\n\t 5. Delete from Binary Tree ";
 cout<<"\n\t 6. Search and replace ";
 cout<<"\n\t 7. Exit ";
 cout<<"\n\t Enter choice : ";
 cin>>choice;
 if(choice<0 || choice>7)
 printf("\n Invalid choice - try again");
 }
 while (choice<0 || choice>7);
 switch(choice) {
case 0:
 int n;
 cout<<"\n Enter number of element: ";
 cin>>n;
 root= create(root,n);
case 1:
 cout<<"\n Enter new element: ";
 cin>>item;
 root= insert(root,item);
 cout<<"\n root is  "<<root->info;
 cout<<"\n Inorder traversal of binary tree is : ";
 inorder(root);
 break;
case 2:
 cout<<"\n Inorder traversal of binary tree is : ";
 inorder(root);
 break;
case 3:
 cout<<"\n Postorder traversal of binary tree is : ";
 postorder(root);
 break;
case 4:
 cout<<"\n Preorder traversal of binary tree is : ";
 preorder(root);
 break;
case 5:
 cout<<"\n Enter the element to be deleted : ";
 cin>>item_no;
 root=delet(root,item_no);
 inorder(root);
 break;
 case 6:
 cout<<"\n Search and replace operation in binary tree ";
 root=search(root);
 break;
default:
 cout<<"\n End of program ";
 exit(0);
 getch();

}
 }
while(choice !=7);
}
 int main(void) {
 BST B;
 clrscr();
 B.menu();
 /* rear = NULL;*/
 return(0);
 }

struct tree * BST::create(struct tree *root, int n){
int item;
for(int i=1;i<n;i++)
{
cout<<"\n Enter new element: ";
cin>>item;
root= insert(root,item); }
return (root);
}

struct tree * BST::insert(struct tree *root, int x) {
 if(!root) {
 root=new tree[sizeof(struct tree)];
 root->info = x;
 root->left = NULL;
 root->right = NULL;
 return(root);
 }
 if(root->info > x)
 root->left = insert(root->left,x); else {
 if(root->info < x)
 root->right = insert(root->right,x);
 }
 return(root);
 }

void BST::inorder(struct tree *ptr) {
 if(ptr != NULL) {
 inorder(ptr->left);
 cout<<ptr->info<<"  ";
 inorder(ptr->right);
 }
 }

void BST::postorder(struct tree *root) {
 if(root != NULL) {
 postorder(root->left);
 postorder(root->right);
 cout<<root->info<<" ";
 }
 return;
 }

 void BST::preorder(struct tree *root) {
 if(root != NULL) {
 cout<<root->info<<" ";
 preorder(root->left);
 preorder(root->right);
 }
 return;
 }
struct tree * BST::delet(struct tree *ptr,int x) {
 struct tree *p1,*p2;
 if(!ptr) {
 cout<<"\n Node not found ";
 return(ptr);
 } else {
 if(ptr->info < x) {
 ptr->right = delet(ptr->right,x);
  } else if (ptr->info >x) {
 ptr->left=delet(ptr->left,x);
 return ptr;
 } else
  {
 if(ptr->info == x)
  {
 if(ptr->left == ptr->right)
  {
 delete ptr;
 return(NULL);
 } else if(ptr->left==NULL)
  {
 p1=ptr->right;
 delete ptr;
 return p1;
 } else if(ptr->right==NULL)
  {
 p1=ptr->left;
 delete ptr;
 return p1;
 } else {
 p1=ptr->right;
 p2=ptr->right;
 while(p1->left != NULL)
 p1=p1->left;
 p1->left=ptr->left;
 delete ptr;
 return p2;
 }
 }
 }
 }
 return(ptr);
 }

struct tree *BST::search(struct tree *root) {
 int no,i,ino;
 struct tree *ptr;
 ptr=root;
 cout<<"\n Enter the element to be searched :";
 cin>>no;
 //fflush(stdin);
 while(ptr) {
 if(no>ptr->info)
 ptr=ptr->right; else if(no<ptr->info)
 ptr=ptr->left; else
 break;
 }
 if(ptr) {
 cout<<"\n Element %d which was searched is found and is = %d",no,ptr-
>info;
 /*printf("\n Do you want replace it, press 1 for yes : ");
 scanf(" %d",&i);
 if(i==1) {
 printf("\n Enter new element :");
 scanf(" %d",&ino);
 ptr->info=ino;
 } else
 printf("\n\t It's okay");*/
 } else
 cout<<"\n Element %d does not exist in the binary tree",no;
 return(root);
 }
