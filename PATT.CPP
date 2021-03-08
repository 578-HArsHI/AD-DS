#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
void main()
{
int i,j,k,l = 0, flag = 0;
clrscr();
for(i = 1; i<=8; i*=2)
{
	l++;
	for(j = 0; j<(10-i-1); j++)
		cout<<setw(5-i)<<"";
	for(k = 0; k < i; k++)
	{
		flag++;
		if (flag >= 4)
		{
			if(k>0 && k<i-1)
				cout<<" "<<i<<" ";
			else
				cout<<"          "<<i<<"               ";
		}
		else if (flag == 3)
			cout<<"          "<<i;
		else if (flag == 2)
			cout<<i<<"          ";
		else if (flag == 1)
			cout<<i;
	}
	cout<<endl<<endl;
}
getch();
}