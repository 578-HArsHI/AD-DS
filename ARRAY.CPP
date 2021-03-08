#include<iostream.h>
#include<conio.h>
void main()
{
	int n,i,j,temp,array[25],num;
	clrscr();
	cout<<"Enter the number of elements :";
	cin>>n;
	cout<<"Enter "<<n<<" elements :";
	for (i = 0; i < n; i++)
	{
		cin>>array[i];
	}
	for (i = 0; i < ( n - 1 ); i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (array[j] < array[j+1])
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	cout<<"Descending order :";
	for (i = 0; i < n; i++)
	{
		cout<<array[i]<<"\t";
	}
	cout<<endl<<"Enter the largest from [ 1 to "<<n<<" ] : ";
	cin>>num;
	if(num > n)
	{
		cout<<"Out of position"<<endl;
	}
	else if(num <= 0)
	{
		cout<<"Wrong entry"<<endl;
	}
	else
	{
		cout<<num<<" largest "<<array[num-1]<<endl;
	}
	for (i = 0; i < ( n - 1 ); i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
        		if (array[j] > array[j+1])
        		{
           			temp = array[j];
           			array[j] = array[j+1];
           			array[j+1] = temp;
        		}
      		}
    	}
	cout<<"Ascending order :";
	for (i = 0; i < n; i++)
    	{
      		cout<<array[i]<<"\t";
  	}
	cout<<endl<<"Enter the smallest from [ 1 to "<<n<<" ] : ";
	cin>>num;
	if(num > n)
	{
		cout<<"Out of position"<<endl;
	}
	else if(num <= 0)
	{
		cout<<"Wrong entry"<<endl;
	}
	else
	{
		cout<<num<<" smallest "<<array[num-1]<<endl;
	}
	getch();
}