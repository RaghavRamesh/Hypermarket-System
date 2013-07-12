#ifndef Perishable_h
#define Perishable_h

#include <string>
#include <iostream>
#include "Product.h"

using namespace std;

class Perishable:public Product
{
private:
	int _ExpiryDate[3];
	double _discount;
public:
	Perishable();
	~Perishable();

	Perishable(int date[], double dis,bool Perish,string Na,string Cat,string Bar,double Pri,string Manu,int Stoc);

	int checkExpire(int a[]);//0 false, 1 for true, -1 for product class
	
	void GETExpiryDate(int a[]);
	double GETdiscount();

	bool SETExpiryDate(int a[]);
	bool SETdiscount(double dis);

	bool checkDateValid(int a[]);


};

#endif
