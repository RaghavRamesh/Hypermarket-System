#ifndef Interface_h
#define Interface_h

#include <iostream>
#include <iomanip>
#include "ListBase.h"
#include "ListDoubly.h"

using namespace std;

class Interface
{
	ListDoubly* Products;

public:
	Interface() {}
	~Interface() {}

	void MAINmenu();//main menu

	void MenuAdd();//option 1
	
	void MenuAddProd();//option 1, sub option 1
	void MenuAddPerishProd();//option 1, sub option 2

	void MenuDeleteProd();//option 2
	
	void MenuReset();//option 3

	void MenuResetIndiv();//option 3 sub option 1

	void MenuSell();//option 4

	void Menu5();//option 5

	void Menu6();//option 6
	
	void Menu7();//option 7 list all prod

    
	Product* GenericMenu(string T);//inputs a string and returns a pointer to the list node
};

#endif 
