// https://omkarnathsingh.wordpress.com/2016/02/09/c-program-for-book-shop/
#include<iostream>
#include<string.h>
#include<stdlib.h>

// Things that don't make sense: I'm assuming defining variables in private makes them unaccessible globally.
// Why we are even using pointers here. 
// new char[20] means an empty array 20 elements long, but why would you have a 20 character long array for an author's name? I think so that we can still store the name of author, but we are using pointers, so can't use string?
// cin >> *price;
// strcmp(), string compare?
// book *B[20]; B[i] = new book; B[i]->feeddata(); i++; Assuming this means everytime you register a new book, it's instance is stored as B[i]. So there is an array of books named B, and access an individiual book with B[i].
// B[i]->feeddata(); equivalent to B[i].feeddata();. B = [Book("Dr Suess"), Book("Ken Kesey"), Book("J.K. Rowling")];

// Experimenting
    // char test1[20];
    // char test2[20];
    // cout << test1 << endl;
    // // strcmp();
    // cin.getline(test1, 20);
    // cout << test1 << endl;
    // int * i;
    // cout << i << endl << &test1 << endl << *i << endl;
using namespace std;

class book	{
private:
	char *author,*title,*publisher;
	float *price;
	int *stock;
public:	
	book()	{
	author= new char[20];
	title=new char[20];
	publisher=new char[20];
	price= new float;
	stock=new int;
	}
	void feeddata();
	void editdata();
	void showdata();
	int search(char[],char[]);
	void buybook();
	
};

void book::feeddata()	{
	cin.ignore();
	cout<<"\nEnter Author Name: ";      cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;   
	
}

void book::editdata()	{
	
	cout<<"\nEnter Author Name: ";      cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   cin.getline(publisher,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;   
	
}

void book::showdata()	{
	cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Position: "<<*stock;   
	
}

int book::search(char tbuy[20],char abuy[20] )	{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else return 0;
		
}

void book::buybook()	{
	int count;
	cout<<"\nEnter Number Of Books to buy: ";
	cin>>count;
	if(count<=*stock)	{
		*stock=*stock-count;
		cout<<"\nBooks Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(*price)*count;
	}
	else
		cout<<"\nRequired Copies not in Stock";
}

int main()	{
	book *B[20];
	int i=0,r,t,choice;
	char titlebuy[20],authorbuy[20];
	while(1)	{
		cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Edit Details Of Book"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;
		
		switch(choice)	{
			case 1:	B[i] = new book;
				B[i]->feeddata();
				i++;	break;
				
			case 2: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						B[t]->buybook();
						break;
					}
				}
				if(t==1)
				cout<<"\nThis Book is Not in Stock";
				
				break;
			case 3: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nBook Found Successfully";
						B[t]->showdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in Stock";
				break;
			
			case 4: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nBook Found Successfully";
						B[t]->editdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in Stock";
				break;
			
			case 5: exit(0);
			default: cout<<"\nInvalid Choice Entered";
			
		}
	}
	
	
	
	
	return 0;
}