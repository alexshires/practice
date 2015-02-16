#ifndef LINKEDLIST
#define LINKEDLIST

#include "node.hpp"


template<class T>
class LinkedList
{
    public :
        //constructors
        LinkedList() ;
        LinkedList(T val) ;

        // basic methods
        void push_back( const T t ) ;
        void delete_node( node<T> * n ) ;
        void remove_dups( ) ;
        void print() ;
        void clear() ;
    
        //advanced emthods

    private :

        node<T> * start ;
        node<T> * end ;
} ;
template class  LinkedList<int>;
template class  LinkedList<double> ;


#endif /*  */
