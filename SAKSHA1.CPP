#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip.h>
void insert(int num,int n);
void delet(int num);
void display();
int array[100], n;
void main()
{
    clrscr();
    int choice, num;
    n = 0;
    while(1)
    {
	cout<<"1.Insert the element \n";
	cout<<"2.Delete the element \n";
	cout<<"3.Display all elements \n";
	cout<<"4.Quit \n";
	cout<<"Enter your choice : ";
	cin>>choice;
	switch(choice)
	{
	case 1:
	    cout<<"Enter the element to be inserted to the list : ";
	    cin>>num;
	    insert(num, n);
	    n = n + 1;
	    break;
	case 2:
	    cout<<"Enter the elements to be deleted from the list: ";
	    cin>>num;
	    delet(num);
	    break;
	case 3:
	    display();
	    break;
	case 4:
	    exit(0);
	    break;
	default:
	    cout<<"Invalid Choice...!!!"<<endl;
	    break;
	}
    }
    getch();
}
void display()
{
    if (n == 0)
    {
	cout<<"Heap is empty \n";
	return;
    }
    for (int i = 0; i < n; i++)
	cout<<" "<<array[i];
    cout<<endl<<n<<endl;
}
void insert(int num, int location)
{
    int parentnode;
    while (location > 0)
    {
	parentnode =(location - 1)/2;
	cout<<parentnode<<endl;
	if (num >= array[parentnode])
	{
	    array[location] = num;
	    return;
	}
	array[location] = array[parentnode];
	location = parentnode;
    }
    array[0] = num;
}