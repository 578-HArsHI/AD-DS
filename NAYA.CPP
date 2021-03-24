#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip.h>
void insert(int num,int n);
void build_minheap(int *a, int n);
void min_heapify(int *a,int i,int n);
void HeapSort(int *a, int n);
void display();
int a[25], n;
void main()
{
    clrscr();
    int choice, num;
    n = 1;
    while(1)
    {
	cout<<"1.Insert the element \n";
	cout<<"2.Create the element \n";
	cout<<"3.Delete all elements \n";
	cout<<"5.Quit \n";
	cout<<"Enter your choice : ";
	cin>>choice;
	switch(choice)
	{
	case 1:
	    cout<<"Enter the element to be inserted to the list : ";
	    cin>>num;
	    n = n + 1;
	    insert(num, n);
            display();
	    break;
        case 2:
            cout<<"Enter no of elements of array : ";
            cin>>n;
	    for (int i = 1; i <= n; i++)
            {
            	cout<<"Enter element "<<(i)<<" : ";
            	cin>>a[i];
            }
	    build_minheap(a,n);
            display();
	    break;
        case 3:
            HeapSort(a,n);
            display();
	    break;
	case 4:
	    display();
	    break;
	case 5:
	    exit(0);
	    break;
	default:
	    cout<<"Invalid Choice...!!!"<<endl;
	    break;
	}
    }
    getch();
}
void insert(int num, int location)
{
    a[location] = num;
    build_minheap(a,n);
}
void build_minheap(int *a, int n)
{
    int k;
    for(int i = 1; i <= n/2; i++)
    {
        k = 1;
        min_heapify(a,k,n);
    }
}
void min_heapify(int *a,int i,int n)
{
    int j, temp;
    j = 2 * i;
    while (j <= n)
    {
	cout<<a[j/2]<<" "<<a[j]<<" "<<a[j+1]<<endl;
        if (a[j/2] > a[j])
        {
            temp = a[j/2];
            a[j/2] = a[j];
            a[j] = temp;
         }
        cout<<a[j/2]<<" "<<a[j]<<" "<<a[j+1]<<endl;
        if (j < n && a[j/2] > a[j+1])
        {
            temp = a[j/2];
            a[j/2] = a[j+1];
            a[j+1] = temp;
         }
         cout<<a[j/2]<<" "<<a[j]<<" "<<a[j+1]<<endl;
         i++;
         j = 2 * i;
         cout<<i<<" "<<j<<endl;
    }
    return;
}
void HeapSort(int *a, int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		min_heapify(a, 1, i - 1);
	}
}
void display()
{
    if (n == 1)
    {
	cout<<"Heap is empty \n";
	return;
    }
    for (int i = 1; i <= n; i++)
	cout<<" "<<a[i];
    cout<<endl;
}