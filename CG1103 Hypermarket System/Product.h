#ifndef Product_h
#define Product_h

#include <string>
#include <iostream>

using namespace std;

class Product
{
private:
    bool _Perishable;
	string _Name;
	string _Category;
	string _Barcode;
	double _Price;
	string _Manufacturer;
	int _Stock;
	int _soldPERmonth;

public:
	Product();
	virtual ~Product();

	Product(bool Perish,string Na,string Cat,string Bar,double Pri,string Manu,int Stoc);
	//like a boss

	string GETName();
	string GETCategory();
	string GETBarcode();
	double GETPrice();
	string GETManufacturer();
	int GETStock();
	int GETsoldPERmonth();


	bool SETName(string Na);
	bool SETCategory(string Cat);
	bool SETBarcode(string Bar);
	bool SETPrice(double Pri);
	bool SETManufacturer(string Manu);
	bool Saleofproducts(int sold);
	bool Restocking(int add);
	void Reset();//resets all sold

	bool CategoryisVALID(string type);

	virtual int checkExpire(int a[]);//-1 to signal useless info
	virtual double GETdiscount();//-1 to signal useless info



};

#endif
