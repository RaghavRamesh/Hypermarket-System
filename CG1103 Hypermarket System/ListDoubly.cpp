#include "ListDoubly.h"
#include "Product.h"
#include "Perishable.h"
ListDoubly::ListDoubly()
: ListBase( ), _head( NULL ){ }

ListDoubly::~ListDoubly()
{
    while (!isEmpty())
	{
		Product* tempt;
		tempt=_head->item;
        remove(*tempt);
	}
}

ListDoubly::ListNode*    ListDoubly::traverseTo( int index ) 
{
    if ( (index < 0) || (index >= getLength()) )
        return NULL;
    else
    {  
        ListNode *cur = _head;

        for ( int skip = 0; skip < index; skip++ )
            cur = cur->next;

        return cur;
    }
}

bool ListDoubly::insert(Product &target)
{
    
    return true;
}

bool ListDoubly::remove(Product &target) 
{
    
    return true;
}

void ListDoubly::output() 
{
	ListNode* travel = _head;
	int i=1; 
	while(travel != NULL)
	{
		cout<<i<<". ";//numbering
		i++;
        
		//function to print
        
		cout<<endl;
		travel=travel->next;//go to next node
	}
	return;
}


Product* ListDoubly::SearchCATEGORY()//search and returns a pointer to that product
{
	return 0;

}

Product* ListDoubly::SearchNAME()//search and returns a pointer to that 
{
	return 0;

}

Product* ListDoubly::SearchBARCODE()//search and returns a pointer to that product
{
	return 0;

}

void ListDoubly::reset()
{


}