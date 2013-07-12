#include "Product.h"

Product::Product()
{
	//initialise to 0
	_Price=0;
	_Stock=0;
	_soldPERmonth=0;

}

Product::~Product()
{


	//empty for now
}


Product::Product(bool Perish,string Na,string Cat,string Bar,double Pri,string Manu,int Stoc)
{
	_Perishable=Perish;
	_Name=Na;
	_Category=Cat;
	_Barcode=Bar;
	_Price=Pri;
	_Manufacturer=Manu;
	_Stock=Stoc;
}



string Product::GETName()
{
	return _Name;
}
string Product::GETCategory()
{
	return _Category;
}
string Product::GETBarcode()
{
	return _Barcode;
}
double Product::GETPrice()
{
	return _Price;
}
string Product::GETManufacturer()
{
	return _Manufacturer;
}
int Product::GETStock()
{
	return _Stock;
}
int Product::GETsoldPERmonth()
{
	return _soldPERmonth;
}

bool Product::SETName(string Na)
{

	_Name=Na;
	return true;
}
bool Product::SETCategory(string Cat)
{
	if(CategoryisVALID(Cat))
	{
		_Category=Cat;
		return true;
	}
	else 
		return false;

}
bool Product::SETBarcode(string Bar)
{
	if(Bar.size()==10)
	{
		_Barcode=Bar;
		return true;
	}
	else 
		return false;

}
bool Product::SETPrice(double Pri)
{
	if(Pri>0)//and 2d.p.
	{
		_Price=Pri;
		return true;
	}
	else
		return false;

}
bool Product::SETManufacturer(string Manu)
{
	_Manufacturer=Manu;
	return true;

}

bool Product::Saleofproducts(int sold)
{
	if(sold<_Stock && sold>0)
	{
		_Stock-=sold;
		_soldPERmonth+=sold;
		return true;
	}

	else 
		return false;//not enough to sell
}

bool Product::Restocking(int add)
{
	if(add>0)
	{
		_Stock+=add;
		return true;
	}
	else
		return false;
}

void Product::Reset()
{
	_soldPERmonth=0;
}


bool Product::CategoryisVALID(string type)
{

	//vigorious checks

	return true;
}


int Product::checkExpire(int a[])
{
	return -1;
}

double Product::GETdiscount()
{
	return -1;
}






