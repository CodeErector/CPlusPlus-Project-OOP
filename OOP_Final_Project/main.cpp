//Header_Files_Here
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <string>
//Standard_Namespace_Here
using namespace std;
//Classes_Here

class author
{
	private:
		char author_name[30], author_town[120], author_type[30];
		int author_ID;
	public:
		void authors_info();
		void add_author();
		void show_authors();
		void authorConfirm_save();
		void author_save();
		friend class book;
};

author addauthor;

class publisher
{
	private:
		char publisher_name[50], publisher_address[150] , publisher_num[16];
		int publisher_ID;
	public:
		void publishers_info();
		void add_publisher();
		void show_publishers();
		void publisherConfirm_save();
		void publisher_save();
		friend class book;
};

publisher addpublisher;

class book: public author , public publisher
{
	private:
		char book_name[30], book_type[30];
		int book_ID, author_ID, publisher_ID, book_price, book_quantity;
	public:
		void books_info();
		void add_book();
		void show_books();
		void bookConfirm_save();
		void book_save();
		friend class issue;
		friend class Return;
};

book addbook;

class issue: public book
{
	private:
		string date, reader_type;
		int issuebook_ID, required_quantity, day, month, year, total;
	public:
		void bookissue_info();
		void add_issue();
		void show_issued();
		void remaining_books();
		void bookissueConfirm_save();
		void bookissue_save();
};

issue addissue;

class Return: public book
{
	private:
		int retbook_ID, day, month, year, late_fine, damage_fine, damagebook, issueday, issuemonth, issueyear, total, lateday, latemonth, lateyear;
		char condition;
	public:
		void bookreturn_info();
		void add_return();
		void show_returns();
		void bookretConfirm_save();
		void bookret_save();
};

Return addreturn;

struct expire_date
{
	int day, month, year;
};

expire_date expiredate;
expire_date returnexpiredate;

//Declare_Functions_Here
void home();

//Start_mainFunction
int main()
{
	home();
	
	return 0;
}

//Functions_Definations
void home()
{
	system("cls");
	cout<<"LIBRARY MANAGEMENT"<<endl<<endl;
	char choice;
	
	cout<<"Press 1 to Authors Information"<<endl;
	cout<<"Press 2 to Publishers Information"<<endl;
	cout<<"Press 3 to Books Information"<<endl;
	cout<<"Press 4 to Book Issue Information"<<endl;
	cout<<"Press 5 to Book Return Information"<<endl;
	cout<<"Press Esc to Quit"<<endl;
	cout<<"Enter Your Choice: ";
	choice=getche();
	
	switch(choice)
	{
		case '1':
			addauthor.authors_info();
			break;
		case '2':
			addpublisher.publishers_info();
			break;
		case '3':
			addbook.books_info();
			break;
		case '4':
			addissue.bookissue_info();
			break;
		case '5':
			addreturn.bookreturn_info();
			break;
		case 27:
			exit(0);
			break;
		default:
			cout<<"\nPlease Check your Input..!!!\n";
			system("pause");
			home();
			break;
	}
}

void author::authors_info()
{
	system("cls");
	cout<<"AUTHORS INFORMATION"<<endl<<endl;
	char authors_choice;
	
	cout<<"Press 1 to Add Author"<<endl;
	cout<<"Press 2 to Show Author"<<endl;
	cout<<"Press Esc to Back to Main Menu"<<endl;
	cout<<"Enter Your Choice: ";
	authors_choice=getche();
	
	switch(authors_choice)
	{
		case '1':
			add_author();
			break;
		case '2':
			show_authors();
			break;
		case 27:
			home();
			break;
		default:
			cout<<"\nPlease Check your Input..!!!\n";
			system("pause");
			authors_info();
			break;
	}	
}

void author::add_author()
{
	int count;
	system("cls");
	cout<<"How Much Records you Want to Enter: ";
	cin>>count;
	
	for(int i;i<count;i++)
	{
		cout<<"Enter Author\'s ID: ";
		cin>>addauthor.author_ID;
		cin.ignore(10,'\n');
		cout<<"Enter Author\'s Name: ";
		cin.getline(addauthor.author_name, 30);
		cout<<"Enter Author\'s Type: ";
		cin.getline(addauthor.author_type, 30);
		cout<<"Enter Author\'s Home Town: ";
		cin.getline(addauthor.author_town, 120);
		
		authorConfirm_save();
	}
	authors_info();
}

void author::show_authors()
{
	system("cls");
	ifstream sain;
	sain.open("authors_info.txt", ios::in);
	while(sain.read((char *)&addauthor, sizeof(addauthor)))
	{
		cout<<"Author\'s ID: "<<addauthor.author_ID<<endl;
		cout<<"Author\'s Name: "<<addauthor.author_name<<endl;
		cout<<"Author\'s Type: "<<addauthor.author_type<<endl;
		cout<<"Author\'s Home Town: "<<addauthor.author_town<<endl<<endl;
	}
	sain.close();
	system("pause");
	authors_info();
}

void publisher::publishers_info()
{
	system("cls");
	cout<<"PUBLISHERS INFORMATION"<<endl<<endl;
	char publishers_choice;
	
	cout<<"Press 1 to Add Publisher"<<endl;
	cout<<"Press 2 to Show Publishers"<<endl;
	cout<<"Press Esc to Back to Main Menu"<<endl;
	cout<<"Enter Your Choice: ";
	publishers_choice=getche();
	
	switch(publishers_choice)
	{
		case '1':
			add_publisher();
			break;
		case '2':
			show_publishers();
			break;
		case 27:
			home();
			break;
		default:
			cout<<"\nPlease Check your Input..!!!\n";
			system("pause");
			publishers_info();
			break;
	}
}

void publisher::add_publisher()
{
	int count;
	system("cls");
	cout<<"How Much Records you Want to Enter: ";
	cin>>count;
	
	for(int i;i<count;i++)
	{
		cout<<"Enter Publisher\'s ID: ";
		cin>>addpublisher.publisher_ID;
		cin.ignore(10,'\n');
		cout<<"Enter Publisher\'s Name: ";
		cin.getline(addpublisher.publisher_name, 50);
		cout<<"Enter Publisher\'s Address: ";
		cin.getline(addpublisher.publisher_address, 150);
		cout<<"Enter Publisher\'s Contact: ";
		cin.getline(addpublisher.publisher_num, 16);
		
		publisherConfirm_save();
	}
	publishers_info();
}

void publisher::show_publishers()
{
	system("cls");
	ifstream spin;
	spin.open("publishers_info.txt", ios::in);
	while(spin.read((char *)&addpublisher, sizeof(addpublisher)))
	{
		cout<<"Publisher\'s ID: "<<addpublisher.publisher_ID<<endl;
		cout<<"Publisher\'s Name: "<<addpublisher.publisher_name<<endl;
		cout<<"Publisher\'s Type: "<<addpublisher.publisher_address<<endl;
		cout<<"Publisher\'s Home Town: "<<addpublisher.publisher_num<<endl<<endl;
	}
	spin.close();
	system("pause");
	publishers_info();
}

void book::books_info()
{
	system("cls");
	cout<<"BOOKS INFORMATION"<<endl<<endl;
	char books_choice;
	
	cout<<"Press 1 to Add Book"<<endl;
	cout<<"Press 2 to Show Books"<<endl;
	cout<<"Press Esc to Back to Main Menu"<<endl;
	cout<<"Enter Your Choice: ";
	books_choice=getche();
	
	switch(books_choice)
	{
		case '1':
			add_book();
			break;
		case '2':
			show_books();
			break;
		case 27:
			home();
			break;
		default:
			cout<<"\nPlease Check your Input..!!!\n";
			system("pause");
			books_info();
			break;
	}
}

void book::add_book()
{
	int count;
	system("cls");
	cout<<"How Much Records you Want to Enter: ";
	cin>>count;
	
	for(int i;i<count;i++)
	{
		cout<<"Enter Book ID: ";
		cin>>addbook.book_ID;
		cin.ignore(10,'\n');
		cout<<"Enter Book Name: ";
		cin.getline(addbook.book_name, 30);
		cout<<"Enter Book Type: ";
		cin.getline(addbook.book_type, 30);
		cout<<"Enter Per Book Price: ";
		cin>>addbook.book_price;
		cout<<"Enter Total Books Quantity: ";
		cin>>addbook.book_quantity;
		cout<<"Enter Author\'s ID: ";
		cin>>addbook.author_ID;
		cout<<"Enter Publisher\'s ID: ";
		cin>>addbook.publisher_ID;
		
		bookConfirm_save();
	}
	books_info();
}

void book::show_books()
{
	int chk=0,flg=0;
	system("cls");
	ifstream sbin;
	sbin.open("books_info.txt", ios::in);
	while(sbin.read((char *)&addbook, sizeof(addbook)))
	{
		cout<<"Book\'s ID: "<<addbook.book_ID<<endl;
		cout<<"Book\'s Name: "<<addbook.book_name<<endl;
		cout<<"Book\'s Type: "<<addbook.book_type<<endl;
		cout<<"Book\'s Price: "<<addbook.book_price<<endl;
		cout<<"Book\'s Total Quantity: "<<addbook.book_quantity<<endl;
		
		ifstream shobin;
		shobin.open("authors_info.txt", ios::in);
		while(shobin.read((char *)&addauthor, sizeof(addauthor)))
		{
			if(addauthor.author_ID==addbook.author_ID)
			{
				cout<<"Book\'s Author: "<<addauthor.author_name<<endl;
				chk==1;
			}
			else if(chk==0)
			{
				cout<<"\nAuthor Not found..!!!";
			}
		}
		shobin.close();
		ifstream shbin;
		shbin.open("publishers_info.txt", ios::in);
		while(shbin.read((char *)&addpublisher, sizeof(addpublisher)))
		{
			if(addpublisher.publisher_ID==addbook.publisher_ID)
			{
				cout<<"Book\'s Publisher: "<<addpublisher.publisher_name<<endl;
				flg=1;
			}
			else if(flg==0)
			{
				cout<<"\nPublisher Not found..!!!";
			}
		}
		shbin.close();
	}
	sbin.close();
	system("pause");
	books_info();
}

void issue::bookissue_info()
{
	system("cls");
	cout<<"BOOK ISSUE INFORMATION"<<endl<<endl;
	char bookissue_choice;
	
	cout<<"Press 1 to Add Book Issue"<<endl;
	cout<<"Press 2 to Show Issued Books"<<endl;
	cout<<"Press 3 to Remaining Quantity of Books"<<endl;
	cout<<"Press Esc to Back to Main Menu"<<endl;
	cout<<"Enter Your Choice: ";
	bookissue_choice=getche();
	
	switch(bookissue_choice)
	{
		case '1':
			add_issue();
			break;
		case '2':
			show_issued();
			break;
		case '3':
			remaining_books();
			break;
		case 27:
			home();
			break;
		default:
			cout<<"\nPlease Check your Input..!!!\n";
			system("pause");
			bookissue_info();
			break;				
	}
}

void issue::add_issue()
{
	int count, flag=0, check=0;
	system("cls");
	cout<<"How Much Records you Want to Enter: ";
	cin>>count;
	
	for(int i;i<count;i++)
	{
		cout<<"Enter Issue Date"<<endl;
		cout<<"Enter Day(1 to 31): ";
		cin>>addissue.day;
		cout<<"Enter Month(1 to 12): ";
		cin>>addissue.month;
		cout<<"Enter Year Please(i.e 2021): ";
		cin>>addissue.year;
		cout<<"Enter Book ID: ";
		cin>>addissue.issuebook_ID;
		cout<<"Enter Reader Type(professional,student,senior): ";
		cin>>addissue.reader_type;
		cout<<"Enter Required Quantity: ";
		cin>>addissue.required_quantity;
		
		ifstream aiin;
		aiin.open("books_info.txt", ios::in);
		while(aiin.read((char *)&addbook, sizeof(addbook)))
		{
			if(addissue.issuebook_ID==addbook.book_ID)
			{
				cout<<"\nYour Required Book is: "<<addbook.book_name;
			}
			else
			{
				cout<<"\nYou Entered a Wrong Book ID..!!!";
				check=1;
			}
		}
		aiin.close();
		
		if(check==0)
		{
			if(addissue.day<=31 && addissue.day>0)
			{
				if(addissue.month>0 && addissue.month<=12)
				{
					if(addissue.month==2 && addissue.day==29)
					{
						if(addissue.year%4==0)
							if(addissue.year%100==0)
								if(addissue.year%400==0)
								{
									expiredate.day=7;
									expiredate.month=addissue.month+1;
									expiredate.year=addissue.year;
									cout<<"\nThe Expire Date is: "<<expiredate.day<<"-"<<expiredate.month<<"-"<<expiredate.year;
								}	
								else
								{
									cout<<"Feb "<<addissue.year<<" Don\'t have "<<addissue.day;
									cout<<endl;
									system("pause");
									flag=1;
									i--;
								}	
							else
							{
								expiredate.day=7;
								expiredate.month=addissue.month+1;
								expiredate.year=addissue.year;
								cout<<"\nThe Expire Date is: "<<expiredate.day<<"-"<<expiredate.month<<"-"<<expiredate.year;
							}
						else
						{
							cout<<"Feb "<<addissue.year<<" Don\'t have "<<addissue.day;
							cout<<endl;
							system("pause");
							flag=1;
							i--;
						}
					}
					else if(addissue.month==2 && addissue.day>29)
					{
						cout<<"Feb"<<" Don\'t have "<<addissue.day;
						cout<<endl;
						system("pause");
						flag=1;
						i--;
					}
					else if(addissue.month==4 || addissue.month==6 || addissue.month==9 || addissue.month==11)
					{
						if(addissue.day<31)
						{
							if(addissue.day==30)
							{
								expiredate.day=7;
								expiredate.month=addissue.month+1;
								expiredate.year=addissue.year;
								cout<<"\nThe Expire Date is: "<<expiredate.day<<"-"<<expiredate.month<<"-"<<expiredate.year;
							}
							else
							{
								expiredate.day=addissue.day+7;
								expiredate.month=addissue.month;
								expiredate.year=addissue.year;
								cout<<"\nThe Expire Date is: "<<expiredate.day<<"-"<<expiredate.month<<"-"<<expiredate.year;
							}
						}
						else
						{
							cout<<endl<<addissue.month<<" Don\'t has "<<addissue.day;
							cout<<endl;
							system("pause");
							flag=1;
							i--;
						}	
					}
					else
					{
						if(addissue.day==31 && addissue.month==12)
						{
							expiredate.day=7;
							expiredate.month=1;
							expiredate.year=addissue.year+1;
							cout<<"\nThe Expire Date is: "<<expiredate.day<<"-"<<expiredate.month<<"-"<<expiredate.year;
						}
						else if(addissue.day==31)
						{
							expiredate.day=7;
							expiredate.month=addissue.month+1;
							expiredate.year=addissue.year;
							cout<<"\nThe Expire Date is: "<<expiredate.day<<"-"<<expiredate.month<<"-"<<expiredate.year;
						}
						else
						{
							expiredate.day=addissue.day+7;
							expiredate.month=addissue.month;
							expiredate.year=addissue.year;
							cout<<"\nThe Expire Date is: "<<expiredate.day<<"-"<<expiredate.month<<"-"<<expiredate.year;
						}
					}
				}
				else
				{
					cout<<"Please Check Your Month...!";
					cout<<endl;
					system("pause");
					flag=1;
					i--;
				}
			}
			else
			{
				cout<<"Please Check Your Day...!";
				cout<<endl;
				system("pause");
				flag=1;
				i--;
			}
			
			if(flag==0)
			{
				if(addissue.reader_type=="professional")
				{
					addissue.total=500*addissue.required_quantity;
					cout<<"\nYour Charges are: "<<addissue.total;
				}
				else if(addissue.reader_type=="student")
				{
					addissue.total=400*addissue.required_quantity;
					cout<<"\nYour Charges are: "<<addissue.total;
				}
				else if(addissue.reader_type=="senior")
				{
					addissue.total=200*addissue.required_quantity;
					cout<<"\nYour Charges are: "<<addissue.total;
				}
				else
				{
					cout<<"\nPlease Check Reader Type Input..!!!";
				}
			}
			
			if(flag==0)
			{
				cout<<endl;
				bookissueConfirm_save();
			}
		}
	}
	bookissue_info();
}

void issue::show_issued()
{
	system("cls");
	ifstream siin;
	siin.open("bookissues_info.txt", ios::out | ios::app);
	while(siin.read((char *)&addissue, sizeof(addissue)))
	{
		cout<<"Book\'s ID: "<<addissue.issuebook_ID<<endl;
		ifstream aiin;
		aiin.open("books_info.txt", ios::in);
		while(aiin.read((char *)&addbook, sizeof(addbook)))
		{
			if(addissue.issuebook_ID==addbook.book_ID)
			{
				cout<<"Book\'s Name: "<<addbook.book_name<<endl;
			}
		}
		aiin.close();
		cout<<"Issue Date: "<<addissue.day<<"-"<<addissue.month<<"-"<<addissue.year<<endl;
		cout<<"Expire Date: "<<expiredate.day<<"-"<<expiredate.month<<"-"<<expiredate.year<<endl;
		cout<<"Reader Type: "<<addissue.reader_type<<endl;
		cout<<"Required Quantity: "<<addissue.required_quantity<<endl;
		cout<<"Total Charges: "<<addissue.total<<endl<<endl;
	}
	siin.close();
	system("pause");
	bookissue_info();
}

void issue::remaining_books()
{
	int rembook_ID;
	system("cls");
	cout<<"Enter Book ID: ";
	cin>>rembook_ID;
	
	ifstream remin;
	remin.open("books_info.txt", ios::in);
	while(remin.read((char *)&addbook, sizeof(addbook)))
	{
		if(rembook_ID==addbook.book_ID)
		{
			cout<<"Your Book is: "<<addbook.book_name<<endl;
			ifstream rbin;
			rbin.open("bookissues_info.txt", ios::in);
			while(rbin.read((char *)&addissue, sizeof(addissue)))
			{
				cout<<"\nRemaining/s: "<<addbook.book_quantity-addissue.required_quantity;
			}
			rbin.close();
		}
		else
		{
			cout<<"Wrong ID Book Not Found..!!!";
		}
	}
	remin.close();
	cout<<endl;
	system("pause");
	bookissue_info();
}

void Return::bookreturn_info()
{
	system("cls");
	cout<<"BOOK RETURN INFORMATION"<<endl<<endl;
	char bookreturn_choice;
	
	cout<<"Press 1 to Add Returns"<<endl;
	cout<<"Press 2 to Show Returns"<<endl;
	cout<<"Press Esc to Back to Main Menu"<<endl;
	cout<<"Enter Your Choice: ";
	bookreturn_choice=getche();
	
	switch(bookreturn_choice)
	{
		case '1':
			add_return();
			break;
		case '2':
			show_returns();
			break;
		case 27:
			home();
			break;
		default:
			cout<<"\nPlease Check your Input..!!!\n";
			system("pause");
			bookreturn_info();
			break;			
	}
}

void Return::add_return()
{
	int count, flag=0, check=0;
	system("cls");
	cout<<"How Much Records you Want to Enter: ";
	cin>>count;
	
	for(int i;i<count;i++)
	{
		cout<<"Enter Book ID: ";
		cin>>addreturn.retbook_ID;
		cout<<"Condition of Book Damage(y/n): ";
		cin>>addreturn.condition;
		cout<<"Damage Book/s: ";
		cin>>addreturn.damagebook;
		cout<<"Date of Issue";
		cout<<"Enter Day(1 to 31): ";
		cin>>addreturn.issueday;
		cout<<"Enter Month(1 to 12): ";
		cin>>addreturn.issuemonth;
		cout<<"Enter Year Please(i.e 2021): ";
		cin>>addreturn.issueyear;
		cout<<"Date of Return";
		cout<<"Enter Day(1 to 31): ";
		cin>>addreturn.day;
		cout<<"Enter Month(1 to 12): ";
		cin>>addreturn.month;
		cout<<"Enter Year Please(i.e 2021): ";
		cin>>addreturn.year;
		
		ifstream arin;
		arin.open("books_info.txt", ios::in);
		while(arin.read((char *)&addbook, sizeof(addbook)))
		{
			if(addreturn.retbook_ID==addbook.book_ID)
			{
				cout<<"\nYour Returning Book is: "<<addbook.book_name;
			}
			else
			{
				cout<<"\nYou Entered a Wrong Book ID..!!!";
				check=1;
			}
		}
		arin.close();
		int chk=0;
		if(check==0)
		{
			
			if(addreturn.day<=31 && addreturn.day>0)
				{
					if(addreturn.month>0 && addreturn.month<=12)
					{
						if(addreturn.month==2 && addreturn.day==29)
						{
							if(addreturn.year%4==0)
								if(addreturn.year%100==0)
									if(addreturn.year%400==0)
									{
										cout<<"\nThe Return Date is: "<<addreturn.day<<"-"<<addreturn.month<<"-"<<addreturn.year;
									}	
									else
									{
										cout<<"Feb "<<addreturn.year<<" Don\'t have "<<addreturn.day;
										cout<<endl;
										system("pause");
										chk=1;
										i--;
									}	
								else
								{
									cout<<"\nThe Return Date is: "<<addreturn.day<<"-"<<addreturn.month<<"-"<<addreturn.year;
								}
							else
							{
								cout<<"Feb "<<addreturn.year<<" Don\'t have "<<addreturn.day;
								cout<<endl;
								system("pause");
								chk=1;
								i--;
							}
						}
						else if(addreturn.month==2 && addreturn.day>29)
						{
							cout<<"Feb"<<" Don\'t have "<<addreturn.day;
							cout<<endl;
							system("pause");
							chk=1;
							i--;
						}
						else if(addreturn.month==4 || addreturn.month==6 || addreturn.month==9 || addreturn.month==11)
						{
							if(addreturn.day<31)
							{
								if(addreturn.day==30)
								{
									cout<<"\nThe Return Date is: "<<addreturn.day<<"-"<<addreturn.month<<"-"<<addreturn.year;
								}
								else
								{
									cout<<"\nThe Return Date is: "<<addreturn.day<<"-"<<addreturn.month<<"-"<<addreturn.year;
								}
							}
							else
							{
								cout<<endl<<addreturn.month<<" Don\'t has "<<addreturn.day;
								cout<<endl;
								system("pause");
								chk=1;
								i--;
							}	
						}
						else
						{
							if(addreturn.day==31 && addreturn.month==12)
							{
								cout<<"\nThe Return Date is: "<<addreturn.day<<"-"<<addreturn.month<<"-"<<addreturn.year;
							}
							else if(addreturn.day==31)
							{
								cout<<"\nThe Return Date is: "<<addreturn.day<<"-"<<addreturn.month<<"-"<<addreturn.year;
							}
							else
							{
								cout<<"\nThe Return Date is: "<<addreturn.day<<"-"<<addreturn.month<<"-"<<addreturn.year;
							}
						}
					}
					else
					{
						cout<<"Please Check Your Month...!";
						cout<<endl;
						system("pause");
						chk=1;
						i--;
					}
				}
				else
				{
					cout<<"Please Check Your Day...!";
					cout<<endl;
					system("pause");
					chk=1;
					i--;
				}
			
				if(chk==0)
				{
					if(addreturn.issueday<=31 && addreturn.issueday>0)
					{
						if(addreturn.issuemonth>0 && addreturn.issuemonth<=12)
						{
							if(addreturn.issuemonth==2 && addreturn.issueday==29)
							{
								if(addreturn.issueyear%4==0)
									if(addreturn.issueyear%100==0)
										if(addreturn.issueyear%400==0)
										{
											returnexpiredate.day=7;
											returnexpiredate.month=addreturn.issuemonth+1;
											returnexpiredate.year=addreturn.issueyear;
											cout<<"\nThe Expire Date is: "<<returnexpiredate.day<<"-"<<returnexpiredate.month<<"-"<<returnexpiredate.year;
										}	
										else
										{
											cout<<"Feb "<<addreturn.issueyear<<" Don\'t have "<<addreturn.issueday;
											cout<<endl;
											system("pause");
											flag=1;
											i--;
										}	
									else
									{
										returnexpiredate.day=7;
										returnexpiredate.month=addreturn.issuemonth+1;
										returnexpiredate.year=addreturn.issueyear;
										cout<<"\nThe Expire Date is: "<<returnexpiredate.day<<"-"<<returnexpiredate.month<<"-"<<returnexpiredate.year;
									}
								else
								{
									cout<<"Feb "<<addreturn.issueyear<<" Don\'t have "<<addreturn.issueday;
									cout<<endl;
									system("pause");
									flag=1;
									i--;
								}
							}
							else if(addreturn.issuemonth==2 && addreturn.issueday>29)
							{
								cout<<"Feb"<<" Don\'t have "<<addreturn.issueday;
								cout<<endl;
								system("pause");
								flag=1;
								i--;
							}
							else if(addreturn.issuemonth==4 || addreturn.issuemonth==6 || addreturn.issuemonth==9 || addreturn.issuemonth==11)
							{
								if(addreturn.issueday<31)
								{
									if(addreturn.issueday==30)
									{
										returnexpiredate.day=7;
										returnexpiredate.month=addreturn.issuemonth+1;
										returnexpiredate.year=addreturn.issueyear;
										cout<<"\nThe Expire Date is: "<<returnexpiredate.day<<"-"<<returnexpiredate.month<<"-"<<returnexpiredate.year;
									}
									else
									{
										returnexpiredate.day=addreturn.issueday+1;
										returnexpiredate.month=addreturn.issuemonth;
										returnexpiredate.year=addreturn.issueyear;
										cout<<"\nThe Expire Date is: "<<returnexpiredate.day<<"-"<<returnexpiredate.month<<"-"<<returnexpiredate.year;
									}
								}
								else
								{
									cout<<endl<<addreturn.issuemonth<<" Don\'t has "<<addreturn.issueday;
									cout<<endl;
									system("pause");
									flag=1;
									i--;
								}	
							}
							else
							{
								if(addreturn.issueday==31 && addreturn.issuemonth==12)
								{
									returnexpiredate.day=7;
									returnexpiredate.month=1;
									returnexpiredate.year=addreturn.issueyear+1;
									cout<<"\nThe Expire Date is: "<<returnexpiredate.day<<"-"<<returnexpiredate.month<<"-"<<returnexpiredate.year;
								}
								else if(addreturn.issueday==31)
								{
									returnexpiredate.day=7;
									returnexpiredate.month=addreturn.issuemonth+1;
									returnexpiredate.year=addreturn.issueyear;
									cout<<"\nThe Expire Date is: "<<returnexpiredate.day<<"-"<<returnexpiredate.month<<"-"<<returnexpiredate.year;
								}
								else
								{
									returnexpiredate.day=addreturn.issueday+7;
									returnexpiredate.month=addreturn.issuemonth;
									returnexpiredate.year=addreturn.issueyear;
									cout<<"\nThe Expire Date is: "<<returnexpiredate.day<<"-"<<returnexpiredate.month<<"-"<<returnexpiredate.year;
								}
							}
						}
						else
						{
							cout<<"Please Check Your Month...!";
							cout<<endl;
							system("pause");
							flag=1;
							i--;
						}
					}
					else
					{
						cout<<"Please Check Your Day...!";
						cout<<endl;
						system("pause");
						flag=1;
						i--;
					}
					//Late Fine 
					addreturn.lateday=addreturn.day-returnexpiredate.day;
					addreturn.latemonth=addreturn.month-returnexpiredate.month;
					addreturn.lateyear=addreturn.year-returnexpiredate.year;
					addreturn.late_fine=addreturn.lateday*10+addreturn.latemonth*10*30+addreturn.lateyear*10*365;
					
					cout<<"\nYour late Duration is: "<<addreturn.lateday<<"Day/s - "<<addreturn.latemonth<<"Month/s - "<<addreturn.lateyear<<"Year/s";
					cout<<"\nYour Fine are: "<<addreturn.late_fine;
					//Damage Fine
					
					if(addreturn.condition=='y')
					{
						ifstream retin;
						retin.open("books_info.txt", ios::in);
						while(retin.read((char *)&addbook, sizeof(addbook)))
						{
							if(addreturn.retbook_ID==addbook.book_ID)
							{
								addreturn.damage_fine=addbook.book_price/2*addreturn.damagebook;
								cout<<"\nYour Damage Fine is: "<<addreturn.damage_fine;
							}
						}
						retin.close();
					}
					else if(addreturn.condition=='n')
					{
						cout<<"\nYour Damage Fine is: "<<addreturn.damage_fine;
					}
					
					addreturn.total=addreturn.damage_fine+addreturn.late_fine;
					cout<<"\nYour Total Fine is: "<<addreturn.total<<endl;
					
					if(flag==0)
					{
						bookretConfirm_save();
					}
				}
		}
	}
	bookreturn_info();
}

void Return::show_returns()
{
	system("cls");
	ifstream srin;
	srin.open("bookreturns_info.txt", ios::in);
	while(srin.read((char *)&addreturn, sizeof(addreturn)))
	{
		cout<<"Book\'s ID: "<<addreturn.retbook_ID<<endl;
		ifstream shrin;
		shrin.open("books_info.txt", ios::in);
		while(shrin.read((char *)&addbook, sizeof(addbook)))
		{
			cout<<"Book\'s Name: "<<addbook.book_name<<endl;
		}
		shrin.close();
		cout<<"Issued Date: "<<addreturn.issueday<<"-"<<addreturn.issuemonth<<"-"<<addreturn.issueyear<<endl;
		cout<<"Expire Date: "<<returnexpiredate.day<<"-"<<returnexpiredate.month<<"-"<<returnexpiredate.year<<endl;
		cout<<"Return Date: "<<addreturn.day<<"-"<<addreturn.month<<"-"<<addreturn.year<<endl;
		cout<<"Late Fine: "<<addreturn.late_fine<<endl;
		cout<<"Book Condition Damage: "<<addreturn.condition<<endl;
		cout<<"Damage Fine: "<<addreturn.damage_fine<<endl;
		cout<<"Total: "<<addreturn.total<<endl<<endl;
	}
	srin.close();
	system("pause");
	bookreturn_info();
}

void author::authorConfirm_save()
{
	char check;
	
	cout<<"Do you want to save this/these Record/s (y/n): ";
	cin>>check;
	
	if(check=='y')
	{
		author_save();
		cout<<"\nRecord/s Saved..!!!"<<endl;
		system("pause");
	}
	else if(check=='n')
	{
		cout<<"\nRecord/s Discarded..!!!"<<endl;
		system("pause");
	}
	else
	{
		cout<<"Please Check Your Input..!!!"<<endl;
		system("pause");
		authorConfirm_save();
	}
}

void publisher::publisherConfirm_save()
{
	char check;
	
	cout<<"Do you want to save this/these Record/s (y/n): ";
	cin>>check;
	
	if(check=='y')
	{
		publisher_save();
		cout<<"\nRecord/s Saved..!!!"<<endl;
		system("pause");
	}
	else if(check=='n')
	{
		cout<<"\nRecord/s Discarded..!!!"<<endl;
		system("pause");
	}
	else
	{
		cout<<"Please Check Your Input..!!!"<<endl;
		system("pause");
		publisherConfirm_save();
	}
}

void book::bookConfirm_save()
{
	char check;
	
	cout<<"Do you want to save this/these Record/s (y/n): ";
	cin>>check;
	
	if(check=='y')
	{
		book_save();
		cout<<"\nRecord/s Saved..!!!"<<endl;
		system("pause");
	}
	else if(check=='n')
	{
		cout<<"\nRecord/s Discarded..!!!"<<endl;
		system("pause");
	}
	else
	{
		cout<<"Please Check Your Input..!!!"<<endl;
		system("pause");
		bookConfirm_save();
	}
}

void issue::bookissueConfirm_save()
{
	char check;
	
	cout<<"Do you want to save this/these Record/s (y/n): ";
	cin>>check;
	
	if(check=='y')
	{
		bookissue_save();
		cout<<"\nRecord/s Saved..!!!"<<endl;
		system("pause");
	}
	else if(check=='n')
	{
		cout<<"\nRecord/s Discarded..!!!"<<endl;
		system("pause");
	}
	else
	{
		cout<<"Please Check Your Input..!!!"<<endl;
		system("pause");
		bookissueConfirm_save();
	}
}

void Return::bookretConfirm_save()
{
	char check;
	
	cout<<"Do you want to save this/these Record/s (y/n): ";
	cin>>check;
	
	if(check=='y')
	{
		bookret_save();
		cout<<"\nRecord/s Saved..!!!"<<endl;
		system("pause");
	}
	else if(check=='n')
	{
		cout<<"\nRecord/s Discarded..!!!"<<endl;
		system("pause");
	}
	else
	{
		cout<<"Please Check Your Input..!!!"<<endl;
		system("pause");
		bookretConfirm_save();
	}
}

void author::author_save()
{
	ofstream asout;
	asout.open("authors_info.txt", ios::out | ios::app);
	asout.write((char *)&addauthor, sizeof(addauthor));
	asout.close();
}

void publisher::publisher_save()
{
	ofstream psout;
	psout.open("publishers_info.txt", ios::out | ios::app);
	psout.write((char *)&addpublisher, sizeof(addpublisher));
	psout.close();
}

void book::book_save()
{
	ofstream bsout;
	bsout.open("books_info.txt", ios::out | ios::app);
	bsout.write((char *)&addbook, sizeof(addbook));
	bsout.close();
}

void issue::bookissue_save()
{
	ofstream biout;
	biout.open("bookissues_info.txt", ios::out | ios::app);
	biout.write((char *)&addissue, sizeof(addissue));
	biout.close();
}

void Return::bookret_save()
{
	ofstream brout;
	brout.open("bookreturns_info.txt", ios::out | ios::app);
	brout.write((char *)&addreturn, sizeof(addreturn));
	brout.close();
}
