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
        void print() ;
        void clear() ;
    
        //advanced emthods

    private :

        node<T> * start ;
        node<T> * end ;
} ;

template<class T>
LinkedList<T>::LinkedList() 
{
    start = NULL ;
    end = start ;
}


template<class T>
LinkedList<T>::LinkedList(T val) 
{
    start = new node<T>(val,NULL) ;
    end = start ;
}

template<class T>
void LinkedList<T>::push_back( const T t ) 
{
    end = new node<T>(t, end);
    if ( start == NULL ) start = end ;
}

template<class T>
void LinkedList<T>::delete_node( node<T> * t ) 
{
    //fint t
    //remove
}


template<class T>
void LinkedList<T>::print( ) 
{
    //iterator
    node<T> * tmpnode = this->end ;
    std::cout << tmpnode << '\t' << start << std::endl ;
    do
    {
        std::cout << tmpnode->getData() << std::endl ;
        tmpnode = tmpnode->getNext() ;
    }
    while (tmpnode != NULL);
}

template class  LinkedList<int>;
template class  LinkedList<double> ;


#endif /*  */
