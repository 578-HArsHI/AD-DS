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
    n = 1;
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
    if (n == 1)
    {
	cout<<"Heap is empty \n";
	return;
    }
    for (int i = 1; i < n; i++)
	cout<<" "<<array[i];
    cout<<endl;
}
void insert(int num, int location)
{
    int parentnode;
    while (location > 1)
    {
	parentnode = location/2;
	cout<<parentnode<<" "<<n<<endl;
	if (num >= array[parentnode])
	{
	    array[location] = num;
	    return;
	}
	array[location] = array[parentnode];
	location = parentnode;
    }
    array[1] = num;
}