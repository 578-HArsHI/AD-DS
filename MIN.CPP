/*
 * C++ Program to Implement Min Heap
 */
#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip.h>
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
void build_minheap(int *a, int n)
{
    int k;
    for(int i = 1; i <= n/2; i++)
    {
        k = 1;
        min_heapify(a,k,n);
    }
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
void main()
{
    clrscr();
    int n, i;
    cout<<"Enter no of elements of array : ";
    cin>>n;
    int a[20];
    for (i = 1; i <= n; i++)
    {
        cout<<"Enter element "<<(i)<<" : ";
        cin>>a[i];
    }
    build_minheap(a,n);
    cout<<"Min Heap : ";
    for (i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    HeapSort(a,n);
    cout<<"Min Heap Sort : ";
    for (i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
    getch();
}