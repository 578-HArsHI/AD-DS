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
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j+1] < temp)
            j = j + 1;
        if (temp <= a[j])
            break;
        else if (temp > a[j])
        {
            a[j/2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}
void build_minheap(int *a, int n)
{
    for(int i = n/2; i >= 1; i--)
    {
        min_heapify(a,i,n);
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
    }i=n/2;
    cout<<i<<endl;
    build_minheap(a,n);
    cout<<"Min Heap : ";
    for (i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }
    getch();
}