#include<iostream>
#include<cmath>
using namespace std;
template <typename t>
class MySet
{
private:
    t *set;
    int size;

public:

    //default constructor

    MySet()
    {
        set = new t[1];
    }

    //parametrised constructor

    MySet(int s)
    {
        size=s;
        set = new t[size];
    }

    //taking input 

    void input()
    {
        
        cout<<" Enter Your Set ";
        for(int i=0; i<size;i++)
        {
            cin>>set[i];
        }
        duplicate(set,size);
    }

    //display function

    void print()
    {
        cout<<" \n your set is : \n";
        for(int i=0;i<size;i++)
        {
            cout<<set[i]<<" ";
        }
    }

    //remove of duplicate 

    void duplicate(t set[] , int &size)
    {
		for(int i=0;i<size;i++)
		{
			for(int j=i+1;j<size;j++)
			{
				if(set[i]==set[j])
				{
					int temp=j+1;
				for(int k=j;k<size;k++,temp++)
				{
					set[k]=set[temp];
				}
				size--;
				}
			}
		}
    
    }
    //powerset
    void powerset()
    {
    	int set_pow=pow(2,size);
    	cout<<"\n{";
    	for(int i=0; i<set_pow;i++)
    	{
    		cout<<"{";
    		for(int j=0;j<size;j++)
    		{
    			if(i&(1<<j))
    			cout<<" "<<set[j]<<" ";
			}
			cout<<"} ,";
		}
		cout<<"}";
	}
	//cardinality
	void cardinality()
	{
		cout<<" cardinality is :";
		cout<<size ;
	}
    void operator +(MySet obj);
    void operator *(MySet obj);
	void operator -(MySet obj);
	void operator ^(MySet obj);
	void operator ==(MySet obj);
};
template <typename t>
    void MySet<t>::operator +(MySet<t> obj)
    {
        MySet <t>temp;
        int i , j;
        temp.size = size+obj.size;
        for(i=0;i<size;i++)
        {
            temp.set[i]=set[i];
        }
        for(i=size,j=0;i<size+obj.size&&j<obj.size;i++,j++)
        {
            temp.set[i]=obj.set[j];
        }
        temp.duplicate(temp.set , temp.size);
        cout<<" \n Set after union \n ";
        temp.print();
    }
    template<typename t>
    void MySet<t>::operator *(MySet<t> obj)
    {
    	MySet <t>temp2(size);
    	int tempsize=0 , flag=0;
    	for(int i=0;i<size;i++)
    	{
    		for(int j=0;j<obj.size;j++)
    		{
    			if(set[i]==obj.set[j])
    			{
    				temp2.set[flag]=set[i];
    				++flag;
    				++tempsize;
    				if(flag==temp2.size-1)
    				{
    					i=size;
					}
					break;
				}
			}
		}
		temp2.size=tempsize;
		cout<<" \n Set after intersection of set1 and set2 \n";
		temp2.print();
	}
template<typename t>
void MySet<t>::operator -(MySet<t> obj)
	{
		MySet temp(size);
		int flag=0;
		int tempsize=0;
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<obj.size;j++)
			{
				if(set[i]!=obj.set[j])
				{
					flag++;
				}
			}
			if(flag==obj.size)
			{
				temp.set[tempsize]=set[i];
				tempsize++;
			}
			flag=0;
		}
		temp.size=tempsize;
		cout<<"\n\nAfter taking difference of the first two sets ,\n";
		temp.print();
	}
template<typename t>
void MySet<t>::operator ^(MySet <t>obj)
{
	int i,j;
	MySet <t>temp1;
	//union
	temp1.size=size+obj.size;
	for(i=0;i<size;i++)
	{
		temp1.set[i]=set[i];
	}
	for(i=size,j=0;i<size+obj.size&&j<obj.size;i++,j++)
	{
		temp1.set[i]=obj.set[j];
	}
	temp1.duplicate(temp1.set,temp1.size);
	//intersection
	MySet <t>temp2(size);
	int flag=0,counter=0;
		for(int i=0;i<size;i++)
		{
			for(int j=0;j<obj.size;j++)
			{
				if(set[i]==obj.set[j])
				{
					temp2.set[flag]=set[i];
					++flag;
					++counter;
					if(flag==temp2.size-1)
					{
						i=size;
					}
					break;
				}
			}
		}
		temp2.size=counter;
	// difference
	MySet <t>Finaltemp(temp1.size);
	 flag=0;
	int indx=0;
	counter=0;
		for(int i=0;i<temp1.size;i++)
		{
			for(int j=0;j<temp2.size;j++)
			{
				if(temp1.set[i]!=temp2.set[j])
				{
					flag++;
				}
			}
			if(flag==temp2.size)
			{
				Finaltemp.set[indx]=temp1.set[i];
				indx++;
				counter++;
			}
			flag=0;
		}
		Finaltemp.size=counter;
		cout<<"\nAfter taking Symmetric difference of the first two sets ,\n";
		Finaltemp.print();
}
template<typename t>
void MySet<t>::operator ==(MySet<t> obj)
{
	if(size==obj.size)
	{
		int flag=0;
		for(int i=0;i<size;i++)
		{
			if(set[i]==obj.set[i])
			{
				flag++;
			}
			else
			{
				break;
			}	
		}	
		if(flag==size)
		{
			cout<<"\n Both sets are equal   \n\n";
		}
		else
		{
			cout<<"\nSets are not equal  \n\n";
		}
	}
	else
	{
		cout<<"\nSets are not equal\n";
	}
	
}
void startmenu()
{
	cout<<"\n Enter your choice which type of set you want \n";
	cout<<" \n Enter 1 for integer set ";
	cout<<"\n Enter 2 for character ";
	cout<<"\n Enter 3 for decimal";
}
void menu()
{
	cout<<"\n There are following operations on sets \n";
	cout<<" \nenter your choice :::::::::::::";
	cout<<"\n Enter 1 for union ";
	cout<<"\n Enter 2 for intersection ";
	cout<<" \n Enter 3 for difference ";
	cout<<"\n Enter 4 for Symmetric difference ";
	cout<<"\n Enter 5 for check two sets are equal or not ";
	cout<<"\n Enter 6 for cardinality of sets ";
	cout<<"\n Enter 7 for power set ";
	
}
template <typename t>
void functioncall(MySet <t>&obj1,MySet <t>&obj2)
{
	int choice;
	cout<<" \nEnter your choice :";
	cin>>choice;
	switch(choice)
	{
		case 1: obj1+obj2;
		break;
		case 2: obj1*obj2;
		break;
		case 3: obj1-obj2;
		break;
		case 4: obj1^obj2;
		break;
		case 5: obj1==obj2;
		break;
		case 6: char ch;
				cout<<" \nEnter a for cardinality of 1st set ";
				cout<<"\nEnter b for cardinality of 2nd set ";
				cin>>ch;
				switch(ch)
				{
					case 'a':obj1.cardinality();
					break;
					case 'b':obj2.cardinality();
					break;
					default :
						cout<<"\nwrong input\n";
				}
		break;
		case 7: char ch1 ;
				cout<<"\n Enter a for power set of 1st set";
				cout<<"\n Enter b for power set of 2nd set";
				cin>>ch1;
				switch(ch1)
				{
					case 'a': cout<<" \n power set of 1st set \n";
							obj1.powerset();
					break;
					case 'b': cout<<"\n powerset of 2nd set \n";
							obj2.powerset();
						break;
					default :
						cout<<"\n wrong choice \n";
				}
		break;
		default :
			cout<<"\n wrong choice \n";
		break;
			
	}
}
int main()
{
	cout<<" \nWelcome to the sets \n";
	int size1,size2,typechoice;
	char wish;
	startmenu();
	cout<<" Enter your choice :: ";
	cin>>typechoice;
	switch(typechoice)
	{
		case 1:
		{
			cout<<" \nEnter the size of 1st set :";
			cin>>size1;
			MySet <int>obj1(size1);
			obj1.input();
			cout<<"\n Enter the size of 2nd set :";
			cin>>size2;
			MySet <int>obj2(size2);
			obj2.input();
			do
			{
				menu();
				functioncall(obj1,obj2);
				cout<<" \ndo you wish to continue (y/n)";
				cin>>wish;
			}while(wish=='y');	
				
		}
		case 2:
		{
			cout<<" \nEnter the size of 1st set :";
			cin>>size1;
			MySet <char>obj1(size1);
			obj1.input();
			cout<<"\n Enter the size of 2nd set :";
			cin>>size2;
			MySet <char>obj2(size2);
			obj2.input();
			do
			{
				menu();
				functioncall(obj1,obj2);
				cout<<" \ndo you wish to continue (y/n)";
				cin>>wish;
			}while(wish=='y');	
				
		}
		case 3:
		{
			cout<<" \nEnter the size of 1st set :";
			cin>>size1;
			MySet <double>obj1(size1);
			obj1.input();
			cout<<"\n Enter the size of 2nd set :";
			cin>>size2;
			MySet <double>obj2(size2);
			obj2.input();
			do
			{
				menu();
				functioncall(obj1,obj2);
				cout<<" \ndo you wish to continue (y/n)";
				cin>>wish;
			}while(wish=='y');	
				
		}
	}
	return 0;
}
