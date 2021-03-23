/*
* C++ Program to Implement Max Heap
 */
#include <stdio.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip.h>
void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j + 1;
        if (temp >= a[j])
            break;
        else if (temp < a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}
void build_maxheap(int *a,int n)
{
    for(int i = n/2; i >= 1; i--)
    {
        max_heapify(a,i,n);
    }
}
void main()
{
    clrscr();
    int n, i;
    cout<<"Enter no of elements of array : ";
    cin>>n;
    int a[25];
    for (i = 1; i <= n; i++)
    {
        cout<<"Enter element "<<(i)<<" : ";
        cin>>a[i];
    }
    build_maxheap(a,n);
    cout<<"Max Heap : ";
    for (i = 1; i <= n; i++)
    {
        cout<<a[i]<<" ";
    }
    getch();
}