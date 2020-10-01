#include<iostream>
#include<fstream>                         // The header file names are diff now you can see
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

using namespace std;			// It is used to declare all the input/output operation as std
/*   CLASS USED */

class Book
{
protected:
	char bookname[50];
	char author[50];
	char category[20];
public:
	char refno[10];
	void CreateBook();
	void ShowBook();
};
void Book::CreateBook()
{
cout<<"\n Enter Book Reference Number..";
cin>>refno;                                             //As 'gets' function is removed from C++ std lib, I used 'cin'
cout<<"\n Enter Book Name..";
cin>>bookname;                                           //As 'gets' function is removed from C++ std lib, I used 'cin'
cout<<"\n Enter Author's name..";
cin>>author;                                             //As 'gets' function is removed from C++ std lib, I used 'cin'
cout<<"\n Enter Category..";
cin>>category;                                           //As 'gets' function is removed from C++ std lib, I used 'cin'
}

void Book::ShowBook()
{
cout<<"\n Book Number - "<<refno;
cout<<"\n Book Name - "<<bookname;
cout<<"\n Author - "<<author;
cout<<"\n Category - "<<category;
}

/* CLASS USED */
class Person:public Book
{
protected:
    char name[20];
public:
    void Create();
    void Show();
    char cardno[10];
    int noofbook;
};

void Person::Create()
{
    cout<<"\n Enter Card No...";
    cin>>cardno;
    cout<<"\n Enter Name of Person...";
    cin>>name;
    cout<<"\n Enter No of Book Issued..";
    cin>>noofbook;
}

void Person::Show()
{
    cout<<"\n Card No - "<<cardno;
    cout<<"\n Person Name - "<<name;
    cout<<"\n No of Book Issued - "<<noofbook;
}

/* FUNCTION TO CREATE A BOOK RECORD */

void AddRecord()
{
   ofstream f1;
   Book B;
     f1.open("Book.txt",ios::out|ios::binary);                 //You forgot to add any sort of file extention so that's why it was not working previously
     B.CreateBook();
     f1.write((char*)&B,sizeof(Book));
    f1.close();
   cout<<"\n Book Record Created !!!!!";
}

/* FUNCTION TO CREATE A RECORD */ 

void AddPerson()
{
   ofstream f1;
   Person P;
   f1.open("Person.txt",ios::out|ios::binary);                 //You forgot to add any sort of file extention so that's why it was not working previously
     P.Create();
     f1.write((char *)&P,sizeof(Person));
    f1.close();
   cout<<"\n Person Record Created !!!!!";
}

/* FUNCTION TO DISPLAY ALL BOOK DETAILS */

void DisplayBook()
{
Book B;
char ch;
ifstream f1;
f1.open("Book.txt",ios::in|ios::binary);                //You forgot to add any sort of file extention so that's why it was not working previously
f1.seekg(0);
while(f1.read((char *)&B,sizeof(B)))
B.ShowBook();
f1.close();
}

/* FUNCTION TO DISPLAY PEOPLE DETAILS */

void DisplayPerson()
{
Person P;
char ch;
ifstream f1;
f1.open("Person.txt",ios::in|ios::binary);                     //You forgot to add any sort of file extention so that's why it was not working previously
f1.seekg(0);
while(f1.read((char *)&P,sizeof(P)))
P.Show();
f1.close();
}

/* FUNCTION TO MODIFY BOOK DETAILS */

void ModifyBook()
{
Book B;
int r1=0;
ifstream f1;
ofstream f2;
f1.open("Book.txt",ios::in|ios::binary);                //You forgot to add any sort of file extention so that's why it was not working previously
f2.open("new.txt",ios::out|ios::binary);
char r[20];
cout<<"\n Enter the book number to be modified..";
cin>>r;                                                 //As 'gets' function is removed from C++ std lib, I used 'cin'
f1.read((char *)&B,sizeof(B));
if(strcmpi(r,B.refno)==0)
  { r1=1;
  B.CreateBook();
  }
f2.write((char *)&B,sizeof(B));
f1.close();
f2.close();
 remove("Book.txt");                                    //You forgot to add any sort of file extention so that's why it was not working previously
 rename("new.txt","Book.txt");
if(r1==1)
{
cout<<"\n Record Is Modified.....";
}
else
{
cout<<"\n Record Not Found..";
}
}

/* FUNCTION TO MODIFY PUBLIC DETAILS */

void ModifyPerson()
{
Person P;
int r1=0;
ifstream f1;
ofstream f2;
f1.open("Person.txt",ios::in|ios::binary);                    //You forgot to add any sort of file extention so that's why it was not working previously
f2.open("new.txt",ios::out|ios::binary);
char r[20];
cout<<"\n Enter the card number of person to be modified..";
cin>>r;                                                 //As 'gets' function is removed from C++ std lib, I used 'cin'
f1.read((char *)&P,sizeof(P));
if(strcmpi(r,P.cardno)==0)
  { r1=1;
  P.Create();
  }
f2.write((char *)&P,sizeof(P));
f1.close();
f2.close();
 remove("Person.txt");
 rename("new.txt","Person.txt");                 //You forgot to add any sort of file extention so that's why it was not working previously
if(r1==1)
{
cout<<"\n Record Is Modified.....";
}
else
{
cout<<"\n Record Not Found..";
}
}

/* FUNCTION TO DELETE BOOK DETAILS */

void DeleteBook()
{
int f=0;
Book B;
ifstream f1;
ofstream f2;
f1.open("Book.txt",ios::in|ios::binary);
f2.open("new.txt",ios::out|ios::binary);                       //You forgot to add any sort of file extention so that's why it was not working previously
char r[20];
cout<<"\n Enter the Book Reference Number to be Deleted..";
cin>>r;                                                        //As 'gets' function is removed from C++ std lib, I used 'cin'
while(f1)
{
f1.read((char *)&B,sizeof(B));
if(strcmpi(r,B.refno)!=0)
 f2.write((char *)&B,sizeof(B));
else
 f=1;
}
f1.close();
f2.close();
remove("Book.txt");
rename("new.txt","Book.txt");                    //You forgot to add any sort of file extention so that's why it was not working previously
if(f==1)
{
cout<<"\n Record is Deleted.....";
}
else
cout<<"\n record not found..";
}

/* FUNCTION TO DELETE PEOPLE DETAILS */

void DeletePerson()
{
int f=0;
Person P;
ifstream f1;
ofstream f2;
f1.open("Person.txt",ios::in|ios::binary);                     //You forgot to add any sort of file extention so that's why it was not working previously
f2.open("new.txt",ios::out|ios::binary);
char r[20];
cout<<"\n Enter the Card Number of Person to be Deleted..";
cin>>r;                                                        //As 'gets' function is removed from C++ std lib, I used 'cin'
while(f1)
{
f1.read((char *)&P,sizeof(P));
if(strcmpi(r,P.cardno)!=0)
 f2.write((char *)&P,sizeof(P));
else
 f=1;
}
f1.close();
f2.close();
remove("Person.txt");
rename("new.txt","Person.txt");
if(f==1)
{
cout<<"\n Record is Deleted.....";
}
else
cout<<"\n record not found..";
}

/* FUNCTION TO ISSUE THE BOOK  */

void Issue()
{
Person P;
Book B;
char cn[10], bn[10];
int found=0,flag=0;
ifstream f1,f2;
ofstream f3;
cout<<"\n !!!!! Book Issue !!!!!  ";
cout<<"\n Enter Person's Card no...";
cin>>cn;
cout<<"\n Enter Book Reference no..";
cin>>bn;
f1.open("Person.txt",ios::in|ios::binary);                     //You forgot to add any sort of file extention so that's why it was not working previously
f2.open("Book.txt",ios::in|ios::binary);
f3.open("temp.txt",ios::out|ios::binary);
while(f1.read((char*)&P,sizeof(Person)) && found==0)
{
 if(strcmpi(P.cardno,cn)==0)
   {
    found=1;
    if(P.noofbook==0)
     {
     while(f2.read((char*)&B,sizeof(Book))&&flag==0)
     {
	if(strcmpi(B.refno,bn)==0)
    {
 P.noofbook++;
 flag=1;
cout<<"\n Book issued Succesfully !!!";
cout<<"\n Write Current Date in backside of book and submit within 20 days.";
cout<<"\n Otherwise fine of Rs.1/day is charged !!!";
    }
     }
     }
      }
      f3.write((char *)&P,sizeof(Person));
       }
	  f1.close();
	  f2.close();
	  f3.close();

	  remove("Person.txt");
	  rename("temp.txt","Person.txt");
    if(flag==0)
      cout<<"\n Book Reference number does not exist !!!";
    if(found==0)
      cout<<"\n Person Record Not Exist..";
}

/* FUNCTION TO RETURN THE BOOK */

void Deposit()
{
Person P;
Book B;
char cn[10],bn[10];
int found=0,flag=0,day,fine;
ifstream f1,f2;
ofstream f3;
cout<<"\n !!! BOOK DEPOSIT !!! ";
cout<<"\n Enter Person's Card No...";
cin>>cn;
cout<<"\n Enter Book Reference No...";
cin>>bn;
f1.open("Person.txt",ios::in|ios::binary);
f2.open("Book.txt",ios::in|ios::binary);
f3.open("temp.txt",ios::out|ios::binary);
while(f1.read((char*)&P,sizeof(Person)))
{
 if(strcmpi(P.cardno,cn)==0)
  {
   found=1;
   if(P.noofbook!=0)
    {
     while(f2.read((char*)&B,sizeof(Book))&&flag==0)
     {
        if(strcmpi(B.refno,bn)==0)
        {
          P.noofbook--;
	  flag=1;
	  cout<<"\n Book Deposited in no of Days";
	  cin>>day;
	  if(day>20)
	   {
	     fine=(day-20)*1;
	     cout<<"\n Fine has to deposited Rs."<<fine;
	   }
	 }  
     }
    }
 }
      f3.write((char *)&P,sizeof(Person));
}
     f1.close();
     f2.close();
     f3.close();
     remove("Person.txt");
     rename("temp.txt","Person.txt");
     if(flag==0)
     cout<<"\n Book Reference no does not exist!!!";
     else
     cout<<"\n Book is deposited...!!!";
    if(found==0)
    cout<<"\n Person Record Not Exist..";
}


/*  MENU  */

void Menu()
{
int choice;
char ch;
do
{
system("cls");
cout<<"\n !!!!!!!!!!! PUBLIC LIBRARY MANAGEMENT SYSTEM !!!!!!!!!!! \n";
cout<<"\n********** Select the operation you would like to perform ********** ";
cout<<"\n";
cout<<"\n 1.Add a Book Record ";
cout<<"\n 2.Add Person Details";
cout<<"\n 3.Display all Records";
cout<<"\n 4.Modify a Book Record ";
cout<<"\n 5.Modify a Person Record ";
cout<<"\n 6.Delete a Book Record ";
cout<<"\n 7.Delete a Person Record ";
cout<<"\n 8.Issue a Book ";
cout<<"\n 9.Return a Book";
cout<<"\n 0.Exit ";
cout<<"\n Enter your choice(1-0)... ";
cin>>choice;
switch(choice)
{
case 1:
       AddRecord();
       break;
case 2:
       AddPerson();
       break;
case 3:
       DisplayBook();
       cout<<"\n";
       DisplayPerson();
       break;
case 4:
       ModifyBook();
       break;
case 5:
       ModifyPerson();
       break;
case 6:
       DeleteBook();
       break;
case 7:
       DeletePerson();
       break;
case 8:
       Issue();
       break;
case 9:
       Deposit();
       break;
case 0:
       cout<<"\n!!!!!!!!!!!!!!! THANK YOU !!!!!!!!!!!!!!!";
       cout<<"\n ------- HAVE A NICE DAY ------- ";
       cout<<"\n          PUBLIC LIBRARY        ";
       break;
default:
       cout<<"\n Wrong Choice..";
       break;
}
cout<<"\n Do you wish to work again?(y/n)";
cin>>ch;
}
while(ch=='y'||ch=='Y');
}


/*  MAIN FUNCTION  */

main()
{
system("cls");                               // It is used to clear the screen clrscr() was defined in conio.h header file and it have been removed from the C++ in new versions
ofstream f("Book");
int ch;
char c;
do
{
system("cls");
cout<<"\n !!!!!!!!!!!!!!!!!!!! WELCOME TO PUBLIC LIBRARY !!!!!!!!!!!!!!!!!!!!  \n ";
cout<<"---------------------------------------------------------------------";
cout<<"\n .......Select the operation you would like to perform.......  \n ";
cout<<"\n 1.Open Book";
cout<<"\n 2.Open Menu";
cout<<"\n 3.Exit ";
cout<<"\n Enter your choice(1-3).. ";
cin>>ch;
switch(ch)
{
case 1:
       cout<<"\n !!!!! Book Record is opened !!!!!";
       DisplayBook();
       break;
case 2:
       cout<<"\n-------------------- Menu is opened -------------------- \n";
       Menu();
       break;
case 3:
       cout<<"\n --- Thanks for Visiting --- ";
       cout<<"\n..... Have a nice day.....";
       break;
default:
       cout<<"\n wrong choice!!";
       break;
}
cout<<"\n Want to go back to main menu?(y/n)";
cin>>c;
}
while(c=='y'||c=='Y');
system("pause");                                 //It is used to hold the screen instead of getch() function
                                                 //As getch() function was decraled in conio.h which have been removed from C++ now
}

/* END */
