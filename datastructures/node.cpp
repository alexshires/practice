// templated linked list
#include "node.hpp"

        
template<class T>
node<T> * node<T>::getNext() 
{
    return this->next ;
}
        
template<class T>
void node<T>::insert( node<T> * p ) 
{
    //swap
    p->next = this->next ;
    this->next = p ;
}
        
template<class T>
node<T> * node<T>::delNext() 
{
    node<T> * tmpnode ;
    if ( next != NULL ) {
        tmpnode = this->next ;
        this->next = next->getNext() ;
    }
    return tmpnode ;
}
        
template<class T>
node<T> * node<T>::get( const T & item, node<T> * pnext) 
{
    node<T> * newnode = new node<T>(item, pnext ) ;
    if ( newnode == NULL ) {
        std::cerr << "failed" << std::endl ;
    }
    return newnode ;
}
