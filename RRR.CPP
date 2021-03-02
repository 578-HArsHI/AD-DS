#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *n;
	struct node *p;
}*start, *last, *left, *right;
int count = 0, found = 0;
class circulardoubly
{
	public:
		node* create_node(int);
		void insert_begin();
		void insert_end();
		void insert_pos();
		void update_begin();
		void update_end();
		void update_pos();
		void delete_begin();
		void delete_end();
		void delete_pos();
		void sort1();
		void sort2();
		void reverse();
		void display();
		void distinct();
		void duplicate();
		void search();
		void split();
		void separate();
		void value();
		void dall();
		void check();
		circulardoubly()
		{
			start = NULL;
			last = NULL;
			left = NULL;
			right = NULL;
		}
};
void main()
{
	int choice;
	clrscr();
	circulardoubly cdl,cd2;
	do
	{
		cout<<"\t\t\t--------------------------------"<<endl;
		cout<<"\t\t\tOperations on doubly linked list"<<endl;
		cout<<"\t\t\t--------------------------------"<<endl;
		cout<<"1.Insert at first\t";
		cout<<"2.Insert at Last\t";
		cout<<"3.Insert at Position"<<endl;
		cout<<"4.Value Update at first\t";
		cout<<"5.Value Update at Last\t";
		cout<<"6.Value Update at Position"<<endl;
		cout<<"7.Delete at first\t";
		cout<<"8.Delete at Last\t";
		cout<<"9.Delete at Position"<<endl;
		cout<<"10.Ascending order\t";
		cout<<"11.Descending order\t";
		cout<<"12.Reverse"<<endl;
		cout<<"13.Display\t\t";
		cout<<"14.Distinct\t\t";
		cout<<"15.Duplicate"<<endl;
		cout<<"16.Search\t\t";
		cout<<"17.Split\t\t";
		cout<<"18.Separate"<<endl;
		cout<<"19.V U AT R P\t\t";
		cout<<"20.Exit\t\t\t";
		cout<<"21.Delete ALL"<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:	cdl.insert_begin();
				cd2.display();
				break;
			case 2:	cdl.insert_end();
				cd2.display();
				break;
			case 3:	cdl.insert_pos();
				cd2.display();
				break;
			case 4:	cdl.update_begin();
				cd2.display();
				break;
			case 5:	cdl.update_end();
				cd2.display();
				break;
			case 6:	cdl.update_pos();
				cd2.display();
				break;
			case 7:	cdl.delete_begin();
				cd2.display();
				break;
			case 8:	cdl.delete_end();
				cd2.display();
				break;
			case 9:	cdl.delete_pos();
				cd2.display();
				break;
			case 10:cdl.sort1();
				cd2.display();
				break;
			case 11:cdl.sort2();
				cd2.display();
				break;
			case 12:cdl.reverse();
				cd2.display();
				break;
			case 13:cd2.display();
				break;
			case 14:cdl.distinct();
				cd2.display();
				break;
			case 15:cdl.duplicate();
				cd2.display();
				break;
			case 16:cdl.search();
				cd2.display();
				break;
			case 17:cdl.split();
				cd2.display();
				break;
			case 18:cdl.separate();
				cd2.display();
				break;
			case 19:cdl.value();
				cd2.display();
				break;
			case 20:cout<<"Successfully Exited"<<endl;
				cd2.display();
				exit(0);
				break;
			case 21:cdl.dall();
				cd2.display();
				break;
			case 22:cdl.check();
				cd2.display();
				break;
			default:cout<<"Wrong Choice...???"<<endl;
				cd2.display();
				break;
		}
	}
	while(choice != 20);
	getch();
}
node* circulardoubly::create_node(int v)
{
	struct node *t;
	t = new(struct node);
	if (t == NULL)
	{
		cout<<"Memory not allocated"<<endl;
		return 0;
	}
	else
	{
		t->info = v;
		t->n = NULL;
		t->p = NULL;
		return t;
	}
}
void circulardoubly::insert_begin()
{
	int value;
	cout<<"Enter the element to be inserted : ";
	cin>>value;
	struct node *t;
	t = create_node(value);
	if ( start == last && start == NULL )
	{
		count++;
		start = last = t;
		start->n = last->n = t->n;
		start->p = last->p = t->p;
		cout<<t->info<<" inserted at first in the empty list"<<endl;
	}
	else
	{
		count++;
		t->n = start;
		start->p = t;
		start = t;
		start->p = last;
		last->n = start;
		cout<<start->info<<" inserted at first"<<endl;
   }
}
void circulardoubly::insert_end()
{
	int value;
	cout<<"Enter the element to be inserted : ";
	cin>>value;
	struct node *t;
	t = create_node(value);
	if ( start == last && start == NULL )
	{
		count++;
		start = last = t;
		start->n= last->n = t->n;
		start->p = last->p= t->p;
		cout<<t->info<<" inserted at last in the empty list"<<endl;
	}
	else
	{
		count++;
		t->p= last;
		last->n= t;
		last = t;
		start->p = last;
		last->n= start;
		cout<<last->info<<" inserted at last"<<endl;
	}
}
void circulardoubly::insert_pos()
{
	int value, pos, i;
	struct node *t, *f, *l;
	cout<<"Enter the element to be inserted : ";
	cin>>value;
	t = create_node(value);
	if ( start == last && start == NULL )
	{
		cout<<"The list is empty, Pls enter the position [ SAY 1 ] : ";
		cin>>pos;
		if ( pos == 1 )
		{
			count++;
			start = last = t;
			start->n = last->n = t->n;
			start->p = last->p = t->p;
			cout<<t->info<<" inserted at first in the empty list"<<endl;
		}
		else
			cout<<"Invalid Position"<<endl;
	}
	else
	{
		cout<<"Enter the position from 1 to "<<count + 1<<" : ";
		cin>>pos;
		if ( pos == 1 )
		{
			count++;
			t->n = start;
			start->p = t;
			start = t;
			start->p = last;
			last->n = start;
			cout<<start->info<<" inserted at first"<<endl;
		}
		else if ( pos == count + 1 )
		{
			count++;
			t->p= last;
			last->n= t;
			last = t;
			start->p = last;
			last->n= start;
			cout<<last->info<<" inserted at last"<<endl;
		}
		else if (pos > 1  && pos <= count)
		{
			f = start;
			for (i = 1;i <= count;i++)
			{
				l = f;
				f = f->n;
				if ( i == pos - 1 )
				{
					count++;
					t->n= f;
					f->p = t;
					t->p= l;
					l->n = t;
					cout<<t->info<<" inserted at position "<<pos<<endl;
					break;
				}
			}
		}
		else
			cout<<"Position out of range"<<endl;
	}
}
void circulardoubly::update_begin()
{
	int value;
	if (start == last && start == NULL) {}
	else
	{
		cout<<"Enter the element to be updated : ";
		cin>>value;
		if ( count == 1 )
		{
			start->info = last->info = value;
			cout<<value<<" updated at first"<<endl;
		}
		else
		{
			start->info = value;
			cout<<start->info<<" updated at first"<<endl;
		}
	}
}
void circulardoubly::update_end()
{
	int value;
	if (start == last && start == NULL) {}
	else
	{
		cout<<"Enter the element to be updated : ";
		cin>>value;
		if ( count == 1 )
		{
			start->info = last->info = value;
			cout<<value<<" updated at last"<<endl;
		}
		else
		{
			last->info = value;
			cout<<last->info<<" updated at last"<<endl;
		}
	}
}
void circulardoubly::update_pos()
{
	int value, pos, i;
	struct node *f;
	if (start == last && start == NULL) {}
	else
	{
		cout<<"Enter the element to be updated : ";
		cin>>value;
		if ( count == 1 )
		{
			cout<<"Enter the position [ SAY 1 ] : ";
			cin>>pos;
			if( pos == 1)
			{
				start->info = last->info = value;
				cout<<value<<" updated at first"<<endl;
			}
			else
				cout<<"Invalid Position"<<endl;
		}
		else
		{
			cout<<"Enter the position from 1  to "<<count<<" : ";
			cin>>pos;
			if ( pos == 1)
			{
				start->info = value;
				cout<<start->info<<" updated at first"<<endl;
			}
			else if ( pos == count)
			{
				last->info = value;
				cout<<last->info<<" updated at last"<<endl;
			}
			else if (pos > 1  && pos < count)
			{
				f = start;
				for (i = 0; i < pos - 1; i++)
				{
					f = f->n;
				}
				f->info = value;
				cout<<f->info<<" updated at position "<<pos<<endl;
			}
			else
				cout<<"Position out of range"<<endl;
		}		
	}
}
void circulardoubly::delete_begin()
{
	struct node *f;
	if (start == last && start == NULL) {cout<<"Nothing to delete, ";}
	else
	{
		f = start;
		if ( count == 1)
		{
			start = last = NULL;
			start->n = last->n = NULL;
			start->p = last->p = NULL;
			cout<<f->info<<" Deleted from first"<<endl;
			count--;
		}
		else
		{
			count--;
			last->n = f->n;
			f->n->p = last;
			start = f->n;
			cout<<f->info<<" Deleted from first"<<endl;
			free(f);
		}
	}
}
void circulardoubly::delete_end()
{
	struct node *f;
	if (start == last && start == NULL) {cout<<"Nothing to delete, ";}
	else
	{
		f = last;
		if ( count == 1)
		{
			start = last = NULL;
			start->n = last->n = NULL;
			start->p = last->p = NULL;
			cout<<f->info<<" Deleted from first"<<endl;
			count--;
		}
		else
		{
			count--;
			start->p = f->p;
			f->p->n = start;
			last = f->p;
			cout<<f->info<<" Deleted from last"<<endl;
			free(f);
		}
	}
}
void circulardoubly::delete_pos()
{
	int pos, i;
	struct node *f, *l;
	if (start == last && start == NULL) {cout<<"Nothing to delete, ";}
	else
	{
		if (count == 1)
		{
			f = start;
			cout<<"Enter the position [ SAY 1 ] : ";
			cin>>pos;
			if( pos == 1 )
			{
				start = last = NULL;
				start->n = last->n = NULL;
				start->p = last->p = NULL;
				cout<<f->info<<" Deleted from first"<<endl;
				count--;
			}
			else
				cout<<"Invalid Position"<<endl;
		}
		else
		{
			cout<<"Enter the position from 1  to "<<count<<" : ";
			cin>>pos;
			if ( pos == 1)
			{
				f = start;
				count--;
				last->n = f->n;
				f->n->p = last;
				start = f->n;
				cout<<f->info<<" Deleted from first"<<endl;
				free(f);
			}
			else if ( pos == count)
			{
				f = last;
				count--;
				start->p = f->p;
				f->p->n = start;
				last = f->p;
				cout<<f->info<<" Deleted from last"<<endl;
				free(f);
			}
			else if (pos > 1  && pos < count)
			{
				f = start;
				for (i = 0; i < pos - 1; i++)
				{
					f = f->n;
					l = f->p;
				}
				l->n = f->n;
				f->n->p = l;
				count--;
				cout<<f->info<<" Deleted from position "<<pos<<endl;
				free(f);
			}
			else
				cout<<"Position out of range"<<endl;
		}	
	}
}
void circulardoubly::sort1()
{
	struct node *t, *f;
	int l=0,i;
	if (start == last && start == NULL) {}
	else
	{
		f = start;
		for (i = 0; i < count; i++)
		{
			t= f->n;
			while (t != start)
			{
				if (f->info > t->info)
				{
					l = f->info;
					f->info = t->info;
					t->info = l;
				}
				t = t->n;
			}
			f = f->n;
		}
	}
}
void circulardoubly::sort2()
{
	struct node *t, *f;
	int l=0,i;
	if (start == last && start == NULL) {}
	else
	{
		f = start;
		for (i = 0; i < count; i++)
		{
			t= f->n;
			while (t != start)
			{
				if (f->info < t->info)
				{
					l = f->info;
					f->info = t->info;
					t->info = l;
				}
				t = t->n;
			}
			f = f->n;
		}
	}
}
void circulardoubly::reverse()
{
	struct node *t, *f;
	int l=0,i;
	if (start == last && start == NULL) {}
	else
	{
		f = start;
		for (i = 0; i < count; i++)
		{
			t= f->n;
			while (t != start)
			{
				l = f->info;
				f->info = t->info;
				t->info = l;
				t = t->n;
			}
			f = f->n;
		}
	}
}
void circulardoubly::display()
{
	struct node *f;
	if (start == last && start == NULL)
	{
		cout<<"The list is empty...!!!"<<endl;
	}
	else
	{
		f = start;
		cout<<"Original Linked list of "<<count<<" elements : ";
		for (int i = 0; i < count - 1; i++)
		{
			cout<<f->info<<"<->";
			f = f->n;
		}
		cout<<f->info<<endl;
	}
}
void circulardoubly::distinct()
{
	struct node *f1, *f2, *f3;
	int c = 0;
	if (start == last && start == NULL) {}
	else
	{
		f1 = start;
		for (int i = 0; i < count; i++)
		{
			f2 = start;
			for (int j = 0; j < i; j++)
			{
				if( f1->info == f2->info )
				{
					break;
				}
				f2 = f2->n;
			}
			if (i == j)
			{
				f3 = start;
				for (int k = 0; k < count; k++)
				{
					if( f1->info == f3->info )
					{
						c++;
					}
					f3 = f3->n;
				}
				cout<<f1->info<<" ";cout<<c<<endl;
				c = 0;
			}
			f1 = f1->n;
		}
	}
}
void circulardoubly::duplicate()
{
	struct node *t, *l, *f;
	if (start == last && start == NULL) {}
	else
	{
		f = start;
		for (int i = 0; i < count; i++)
		{
			t= f->n;
			while (t != start)
			{
				if (f->info == t->info)
				{
					if(t == last)
					{
						count--;
						start->p = t->p;
						t->p->n = start;
						last = t->p;
						cout<<t->info<<" Deleted from last"<<endl;
						free(t);
						t = last->n;
					}
					else
					{
						l = t->p;
						l->n = t->n;
						t->n->p = l;
						count--;
						cout<<t->info<<" Deleted from position "<<endl;
						free(t);
						t = l->n;
					}
				}
				else
					t = t->n;
			}
			f = f->n;
		}
	}
}
void circulardoubly::search()
{
	int pos = 0, flag = 0, value;
	struct node *f;
	if (start == last && start == NULL) {}
	else
	{
		cout<<"Enter the value to be searched : ";
		cin>>value;
		f = start;
		for (int i = 0; i < count; i++)
		{
			pos++;
			if (f->info == value)
			{
				flag++;
				if (flag == 1)
					cout<<"Element "<<value<<" found at position : "<<pos;
				else if (flag > 1 && flag <= count)
					cout<<" , "<<pos;
			}
			f = f->n;
		}
		if (flag == 0)
			cout<<"Element "<<value<<" not found in the list";
		else if (flag == 1)
			cout<<endl<<"Element "<<value<<" entered "<<flag<<" time"<<endl;
		else
			cout<<endl<<"Element "<<value<<" entered "<<flag<<" times"<<endl;
	}
}
void circulardoubly::split()
{
	int pos = 0, i, value;
	struct node *f, *t;
	if ( start == last && start == NULL ){}
	else
	{
		if(count >= 2)
		{
			cout<<"Enter the position : ";
			cin>>pos;
			if (pos >= 2 && pos <= count)
			{
				
				for (i = 0; i < pos; i++)
				{
					count--;
					f = last;
					start->p = f->p;
					f->p->n = start;
					last = f->p;
					value = f->info;
					free(f);
					t = create_node(value);
					cout<<t->p->info<<"<-"<<t->info<<"->"<<t->n->info<<" CREATED "<<value<<" DELETED "<<endl;
					if ( right == NULL && left == NULL )
					{
						found++;
						left = right = t;
						left->n = right->n = t->n;
						left->p = right->p = t->p;
					}
					else
					{
						found++;
						t->n = left;
						left->p = t;
						left = t;
						left->p = right;
						right->n = left;
					}
				}
				t = left;
				cout<<"Second Linked list of "<<found<<" elements : ";
				for (i = 0; i < found - 1; i++)
				{
					cout<<t->info<<"<->";
					t = t->n;
				}
				cout<<t->info<<endl;
			}
			else if ( pos < 2)
				cout<<"Invalid Position"<<endl;
			else if ( pos > count)
				cout<<"Position out of range"<<endl;
		}
		else
			cout<<"You entered only one element"<<endl;
	}
}
void circulardoubly::separate()
{
	struct node *f;
	int i, j = 0;
	if (start == last && start == NULL){}
	else
	{
		f = start;
		cout<<"EVEN NUMBERS : ";
		for ( i = 0; i < count; i++)
		{
			if(f->info % 2 == 0)
				{j++;cout<<f->info<<"   ";}
			f = f->n;
		}
		if( j == 0)
			cout<<"NO EVEN NUMBERS";
		j = 0;
		f = start;
		cout<<endl<<"ODD NUMBERS : ";
		for ( i = 0; i < count; i++)
		{
			if(f->info % 2 != 0)
				{j++;cout<<f->info<<"   ";}
			f = f->n;
		}
		if( j == 0)
			cout<<"NO ODD NUMBERS";
		j = 0;
		cout<<endl;
	}
}
void circulardoubly::value()
{
	int pos = 0, flag = 0, v1, v2;
	struct node *f1, *f2;
	if (start == last && start == NULL) {}
	else
	{
		cout<<"Enter the value to be searched : ";
		cin>>v1;
		f1 = start;
		for (int i = 0; i < count; i++)
		{
			pos++;
			if (f1->info == v1)
			{
				flag++;
				if (flag == 1)
				{
					cout<<"Enter the value to be updated : ";
					cin>>v2;
					cout<<v1<<" "<<pos<<" ";
				}
				else if (flag > 1 && flag <= count)
					cout<<v1<<" "<<pos<<" ";
				if ( pos == 1)
				{
					start->info = v2;
					cout<<start->info<<" updated at first "<<pos<<endl;
				}
				else if ( pos == count)
				{
					last->info = v2;
					cout<<last->info<<" updated at last "<<pos<<endl;
				}
				else if (pos > 1  && pos < count)
				{
					f2 = start;
					for (i = 0; i < pos - 1; i++)
					{
						f2 = f2->n;
					}
					f2->info = v2;
					cout<<f2->info<<" updated at position "<<pos<<endl;
				}
			}
			f1 = f1->n;
		}
		if (flag == 0)
			cout<<"Element "<<v1<<" not found in the list"<<endl;
		else if (flag == 1)
			cout<<"Element "<<v1<<" entered "<<flag<<" time"<<endl;
		else
			cout<<"Element "<<v1<<" entered "<<flag<<" times"<<endl;
	}
}
void circulardoubly::dall()
{
	struct node *f;
	if (start == last && start == NULL) {cout<<"Nothing to delete, ";}
	else
	{
		for (int i = 0; i < count; i++)
		{
		if ( i == count - 1)
		{
			f = start;
			start = last = NULL;
			start->n = last->n = NULL;
			start->p = last->p = NULL;
			cout<<f->info<<" Deleted"<<endl;
		}
		else
		{
			f = start;
			last->n = f->n;
			f->n->p = last;
			start = f->n;
			cout<<f->info<<" Deleted"<<endl;
			free(f);
		}
		}
		count = 0;
	}
}
void circulardoubly::check()
{
	struct node *f;
	if (start == last && start == NULL)
	{
		cout<<"The list is empty...!!!"<<endl;
	}
	else
	{
		f = start;
		for (int i = 1; i < count; i++)
		{
			cout<<i<<"."<<f->p->info<<"<-"<<f->info<<"->"<<f->n->info<<endl;
			f = f->n;
		}
		cout<<i<<"."<<f->p->info<<"<-"<<f->info<<"->"<<f->n->info<<endl;
		f = left;
		for (i = 1; i < found; i++)
		{
			cout<<i<<"."<<f->p->info<<"<-"<<f->info<<"->"<<f->n->info<<endl;
			f = f->n;
		}
		cout<<i<<"."<<f->p->info<<"<-"<<f->info<<"->"<<f->n->info<<endl;
	}
}