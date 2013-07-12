#include "ListBase.h"
#include "Product.h"
#include "Perishable.h"
class ListDoubly : public ListBase 
{
    private:
        struct ListNode {
            Product* item;        
            ListNode *next;
			ListNode *prev;
        };
        ListNode* _head;

        ListNode* traverseTo( int index );

    public:
        ListDoubly();
        ~ListDoubly();

     bool insert(Product &target);
     bool remove(Product &target);
     void output();
	 void reset();

	 
	Product* SearchCATEGORY();//search and returns a pointer to that product
	Product* SearchNAME();//search and returns a pointer to that product
	Product* SearchBARCODE();//search and returns a pointer to that product
  
}; 