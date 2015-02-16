#include "list.hpp"

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
    for ( node<T> * it1 = end ; it1 != NULL ; it1 = it1->getNext() )
    {
        std::cout << it1 << '\t' << it1->getData()  << std::endl ;
    }
}


template<class T>
void LinkedList<T>::remove_dups( ) 
{
    //two iterators through list
    // order n(n-1)/2 - triangular
    for ( node<T> * it1 = end ; it1 != NULL ; it1 = it1->getNext() )
    {
        std::cout << it1->getData()  << std::endl ;
        for ( node<T> * it2 = it1->getNext() ; it2 != NULL ; it2 = it2->getNext() )
        {
            if ( it1->getData() == it2->getData() ) //assume comparison works
            {
                std::cout << "print dup" << std::endl ;
            }
        }
    }
}

