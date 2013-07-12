#ifndef __LISTBASE_H__
#define __LISTBASE_H__

#include <string>
#include <sstream>
using namespace std;
#include "Product.h"
#include "Perishable.h"

class ListBase {

protected:
    int _size;
        
public:
    ListBase() { _size = 0; }
    virtual ~ListBase() {}

    bool isEmpty()  { return (_size == 0) ;}
    int getLength() { return _size; }
    
    //The base add function calls the overridden insert method
    //implemented in the subclass!
    bool add(const int& newItem)
    {
       return insert(getLength(), newItem);
    }
 
	virtual bool insert(int index, const int& newItem) {return true;}
	virtual bool remove(int index) {return true;}
	virtual bool retrieve(int index, int& dataItem) {return true;}
	virtual void output() {}
   
    //virtual string toString() = 0;  

	virtual Product* SearchCATEGORY();//search and returns a pointer to that product
	virtual Product* SearchNAME();//search and returns a pointer to that product
	virtual Product* SearchBARCODE();//search and returns a pointer to that product
}; 

#endif