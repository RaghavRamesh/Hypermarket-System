#include "Interface.h"
#include "Product.h"
#include "Perishable.h"
#include<string>
using namespace std;

void title()
{
    cout<<"\n\n";
    cout<<setfill('-')<<setw(80)<<""<<endl;
    cout<<"|           CEB Hypermarket Inventory Control and Monitoring System            |"<<endl;
    cout<<setfill('-')<<setw(80)<<""<<endl;
}

void Interface::MAINmenu()
{
	int x=1; 

	while(x==1)//infinite loop. step out if quit
	{
		title();

		cout<<"|1. Add New Product\n";
		cout<<"|2. Delete Product\n";
		cout<<"|3. Reset Product Sales\n";
		cout<<"|4. Sell Product\n";
		cout<<"|5. Restock Product\n";
		cout<<"|6. Generate Statistics\n";
		cout<<"|7. List All Products\n";
		cout<<"|8. Load Data\n";
		cout<<"|9. Quit\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;//fillers
		cout<<"\n";
		cout<<"Please input your choice(1-9): ";

		char choice;

		choice=getchar();

		cin.ignore(1000,'\n');//clear the buffer
		

		switch(choice)
		{
		case '1':
			//option 1. add product 
			MenuAdd();
			break;
		
		case '2':
			//option 2. delete product
			MenuDeleteProd();
			break;
		
		case '3':
			//option 3. reset sales
			MenuReset();
			break;
			
		case '4':
			//option 4. sell product
			MenuSell();
			break;

		case '5':
			//option 5. restock
			Menu5();
			break;

		case '6':
			//option 6. output
			Menu6();
			break;
		case '7':
			Menu7();
			break;

		case '8':
			//load from file
			cout<<"load successful"<<endl;

			getchar();
			break;
			
		case '9':
			//save all data
			 x=0; //to exit the loop
			break;

		default: //failsafe

			cout<<"there is no such command\n";
			getchar();
		}
	}
	return;
}


void Interface::MenuAdd()
{
	int x=1; 

	while(x==1)//infinite loop. step out if quit
	{
		//menu
		title();

		cout<<" Add New Product\n\n";
		
		cout<<"|1. Add New Non-perishable Product\n";
		cout<<"|2. Add New Perishable Product\n";
		cout<<"|3. Return to main menu\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;
		cout<<"\n";
		cout<<"Please input your choice(1-3): ";
		

		char choice=getchar();

		cin.ignore(1000,'\n');//clear the buffer
		
		switch (choice)
		{

		case '1':
			//menu option 1. add product
			MenuAddProd();
			break;

		case '2':
			//menu option 2. add perishable product
			MenuAddPerishProd();
			break;

		case '3':
			x=0; //to exit the loop
			break;

		default: //failsafe
			cout<<"there is no such command\n";
			getchar();
			getchar();
		}

	return;
	}
}


void Interface::MenuAddProd()
{
	int x=1; 

	while(x==1)//infinite loop. step out if quit
	{
		//menu
		title();

		cout<<" Add New Non-perishable Product\n\n";

		//run create new product
		//just for presentation
		string name,cate,barNo,manu;
		double price;
		int stock;
        cout << "Please Enter Name: ";
		getline(cin,name);
		cout<<"Please Enter Category: ";
		getline(cin,cate);
		cout<<"Please Enter Barcode Number: ";
		getline(cin,barNo);
		cout<<"Please Enter Manufacturer: ";
		getline(cin,manu);
		cout<<"Please Enter Price: ";
		cin>>price;
		cout<<"Please Enter Number in Sctock of This Product: ";
		cin>>stock;
		
		cout<<"Product "<<name<<" Added Successfully"<<endl;
        //end here
        cin.ignore(1000,'\n');
		cout<<"Do you wish to add more Non-perishable Product? (Y/N) "<<endl;

		char choice = toupper( getchar() ); //read choice and convert to caps
		
		cin.ignore(1000,'\n');//clear the buffer

		if(choice!='Y')
			x=0; //to exit the loop
		
	}
}

void Interface::MenuAddPerishProd()
{
	int x=1; 

	while(x==1)//infinite loop. step out if quit
	{
		//menu
		title();

		cout<<" Add New perishable Product\n\n";

		//run create new non-perishable product
		//just for presentation
		string name,cate,barNo,manu;
		double price,discount;
		int stock,day,month,year;
        cout << "Please Enter Name: ";
		getline(cin,name);
		cout<<"Please Enter Category: ";
		getline(cin,cate);
		cout<<"Please Enter Barcode Number: ";
		getline(cin,barNo);
		cout<<"Please Enter Manufacturer: ";
		getline(cin,manu);
		cout<<"Please Enter Price: ";
		cin>>price;
		cout<<"Please Enter Number in Sctock of This Product: ";
		cin>>stock;
		cout<<"Please Enter Expiry Date(DD MM YYYY): ";
		cin>>day>>month>>year;
		cout<<"Please Enter Discount Percentage(eg.50% input 50): ";
		cin>>discount;
        cout<<"Perishable Product "<<name<<" Added Successfully"<<endl;

        cin.ignore(1000,'\n');
		cout<<"Do you wish to add more perishable Product? (Y/N) "<<endl;

		char choice = toupper( getchar() ); //read choice and convert to caps

		
		cin.ignore(1000,'\n');//clear the buffer

		if(choice!='Y')
			x=0; //to exit the loop
		
	}
}


void Interface::MenuDeleteProd()
{
	int x=1; 
	
	while(x==1)//infinite loop. step out if quit
	{
		Product* tempt;
		tempt= (GenericMenu(" Delete Product"));

		if(tempt==NULL)
			return;

		Products->remove(*tempt);

		cout<<"Do you wish to Delete other Products? (Y/N) "<<endl;

		char choice = toupper( getchar() ); //read choice and convert to caps

		cin.ignore(1000,'\n');//clear the buffer

		if(choice!='Y')
			x=0; //to exit the loop
	}

	return;
}

void Interface::MenuReset()
{
	int x=1;

	while(x==1)//infinite loop. step out if quit
	{
		//menu
		title();

		cout<<" Reset Product Sales\n\n";

		cout<<"|1. Reset all\n";
		cout<<"|2. Reset individual\n";
		cout<<"|3. Return to main menu\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<"\n";
        cout<<"please input your choice(1-3): ";
		char choice=getchar();

		cin.ignore(1000,'\n');//clear the buffer
		
		switch (choice)
		{

		case '1':
			Products->reset();
			//x=0;
			break;

		case '2':
			//option 2. reset individual
			MenuResetIndiv();
			break;

		case '3':
			x=0; //to exit the loop
			break;

		default: //failsafe
			cout<<"there is no such command\n";
			getchar();
			getchar();
		}
		
	return;
	}
}


void Interface::MenuResetIndiv()
{
	int x=1;

	while(x==1)//infinite loop. step out if quit
	{
		Product* tempt;
		tempt= (GenericMenu(" Reset individual Product Sales"));

		if(tempt==NULL)
			return;
		
		tempt->Reset();

		cout<<"Do you wish to Restock other Products? (Y/N) "<<endl;

		char choice = toupper( getchar() ); //read choice and convert to caps

		cin.ignore(1000,'\n');//clear the buffer

		if(choice!='Y')
			x=0; //to exit the loop
	}
	return;
	
}


void Interface::MenuSell()
{
	int x=1;

	while(x==1)//infinite loop. step out if quit
	{
		Product* tempt;
		tempt= (GenericMenu(" sell Product"));

		if(tempt==NULL)
			return;

		cout<<"how many do you wish to sell?\n";
		int stock;
		cin>>stock;
		bool check = tempt->Saleofproducts(stock);

		if(!check)
			cout<<"something wrong with the input\n";

		else
		{
		cout<<"Do you wish to Sell other Products? (Y/N) "<<endl;

		char choice = toupper( getchar() ); //read choice and convert to caps

		
		cin.ignore(1000,'\n');//clear the buffer

		if(choice!='Y')
			x=0; //to exit the loop
		}
	}
		
	return;
	
}


void Interface::Menu5()
{
	int x=1;

	while(x==1)//infinite loop. step out if quit
	{
		Product* tempt;
		tempt= (GenericMenu(" Restock Product"));

		if(tempt==NULL)
			return;

		cout<<"how many do you wish to add?\n";
		int stock;
		cin>>stock;
		bool check = tempt->Restocking(stock);

		if(!check)
			cout<<"something wrong with the input\n";

		else
		{
		cout<<"Do you wish to Restock other Products? (Y/N) "<<endl;

		char choice = toupper( getchar() ); //read choice and convert to caps

		
		cin.ignore(1000,'\n');//clear the buffer

		if(choice!='Y')
			x=0; //to exit the loop
		}
	}

	return;
	
}




void Interface::Menu6()
{
	int x=1;

	while(x==1)//infinite loop. step out if quit
	{
		//menu
		cout<<"\n\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;
		cout<<"|           CEB Hypermarket Inventory Control and Monitoring System            |"<<endl;
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<" Generate statistics\n\n";

		
		cout<<"|1. Top X selling product\n";
		cout<<"|2. Best selling product in 1 given category\n";
		cout<<"|3. Best selling manufacturer\n";
		cout<<"|4. Return to main menu\n";
		cout<<setfill('-')<<setw(80)<<""<<endl;

		cout<<"\n";
		cout<<"Please input your choice(1-4): ";

		char choice=getchar();

		cin.ignore(1000,'\n');//clear the buffer

		string str;
		switch (choice)
		{

		case '1':
			int y;
			cout<<"X= ";
			cin>>y;
			//menu option 1. top x selling
			break;

		case '2':
			cout<<"Please enter category you want: ";
			getline(cin,str);
			//menu option 2. best selling in category
			break;

		case '3':
			cout<<"Please enter manufacturer you want: ";
			getline(cin,str);
			//menu option 3. best selling in manufacturer
			break;

		case '4':
			x=0; //to exit the loop
			break;

		default: //failsafe
			cout<<"there is no such command\n";
			getchar();
			getchar();
		}
		//cin.ignore(1000,'\n');
		if(x!=0)
		{
		cout<<"Do you wish to see other Product Sales? (Y/N) "<<endl;

		char choice = toupper( getchar() ); //read choice and convert to caps

		
		cin.ignore(1000,'\n');//clear the buffer

		if(choice!='Y')
			x=0; //to exit the loop
		}
	}
	
	return;
	
}

void Interface::Menu7() //list all products
{
    //For now lists only Products of non-peri
    cout << "Output Products" << endl;

}

Product* Interface::GenericMenu(string T)//inputs a string and returns a pointer to the list node
{
	//menu
	title();

	cout<<T<<"\n\n";

	cout<<"|1. Search by categeory\n";
	cout<<"|2. Search by name\n";
	cout<<"|3. Search by barcode number\n";
	cout<<"|4. Quit to Main menu\n";
	cout<<setfill('-')<<setw(80)<<""<<endl;

	//NEED A SCREEN REFRESH
	cout<<"\n";
	cout<<"Please input your choice(1-4): ";

	//x is placeholder incase of default input
	int x;
	do
	{
		x=0;//always assume correct
		char choice=getchar();

		cin.ignore(1000,'\n');//clear the buffer
		string str;

		switch (choice)
		{
		case '1':
			cout<<"Please enter the Category: ";
			getline(cin,str);
			return Products->SearchCATEGORY();//search and returns a pointer

		case '2':
			cout<<"Please enter the Name: ";
			getline(cin,str);
			return Products->SearchNAME();//search and returns a pointer

		case '3':
			cout<<"Please enter the Barcode Number: ";
			getline(cin,str);
			return Products->SearchBARCODE();//search and returns a pointer

		case '4':
			return NULL;//quit so taht all funtion does nothing

		default:
			x=1;
			cout<<"there is no such command\n";
			getchar();
			getchar();
			
		}
	}
	while(x==1);

	return NULL;
}
		





