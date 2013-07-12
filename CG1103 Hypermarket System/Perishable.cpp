#include "Perishable.h"


Perishable::Perishable() : Product()
{
	
	_ExpiryDate[0]=0;
	_ExpiryDate[1]=0;
	_ExpiryDate[2]=0;

	_discount=0;

}
	
Perishable::Perishable(int date[], double dis,bool Perish,string Na,string Cat,string Bar,double Pri,string Manu,int Stoc) :
Product(Perish,Na,Cat,Bar,Pri,Manu,Stoc)
{
	
	_ExpiryDate[0]=date[0];
	_ExpiryDate[1]=date[1];
	_ExpiryDate[2]=date[2];

	_discount=dis;
}



int Perishable::checkExpire(int a[3])
{
	//compare year month day order

	if(a[2]>_ExpiryDate[2])
		return 0;
	else
	{
		if(a[1]>_ExpiryDate[1])
			return 0;	

		else
			if(a[0]>_ExpiryDate[0])
				return 0;
	}

	return 1;

}

void Perishable::GETExpiryDate(int a[])
{
	a[0]=_ExpiryDate[0];
	a[1]=_ExpiryDate[1];
	a[2]=_ExpiryDate[2];
}

double Perishable::GETdiscount()
{
	return _discount;
}


bool Perishable::SETExpiryDate(int a[])
{
	if(checkDateValid(a))//whole series of checks
	{
		_ExpiryDate[0]=a[0];
		_ExpiryDate[1]=a[1];
		_ExpiryDate[2]=a[2];
		return true;
	}
	else 
		return false;

}
bool Perishable::SETdiscount(double dis)
{
	//should include dis 2 d.p.
	if(dis <100 && dis>0)
	{
		_discount = dis;
		return true;
	}
	else return false;
}


bool Perishable::checkDateValid(int a[])
{
	//whole series of checks
	return true;


}

Perishable::~Perishable()
{
	//nothing for now


}