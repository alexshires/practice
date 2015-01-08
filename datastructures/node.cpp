// templated linked list
#include "node.hpp"

template<class T>
Node<T>::Node() 
{
    this->data = 0 ;
    this->next = NULL ;
} 

        
template<class T>
Node<T>::Node( const T & item, Node<T> *pnext ) 
{
    this->data = item ;
    this->next = pnext ;
}
        
template<class T>
Node<T> * Node<T>::getNext() 
{
    return this->next ;
}
        
template<class T>
void Node<T>::insert( Node<T> * p ) 
{
    //swap
    p->next = this->next ;
    this->next = p ;
}
        
template<class T>
Node<T> * Node<T>::delNext() 
{
    Node<T> * tmpNode ;
    if ( next != NULL ) {
        tmpNode = this->next ;
        this->next = next->getNext() ;
    }
    return tmpNode ;
}
        
template<class T>
Node<T> * Node<T>::get( const T & item, Node<T> * pnext) 
{
    Node<T> * newNode = new Node<T>(item, pnext ) ;
    if ( newNode == NULL ) {
        std::cerr << "failed" << std::endl ;
    }
    return newNode ;
}
