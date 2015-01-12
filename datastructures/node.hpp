// templated linked list

#ifndef NODE
#define NODE

#include <iostream>

template<class T> 
class node
{
    public : 
        node() ; //default cosntructor
        //real cosntructor
        node( T item, node<T> * pnext = NULL ) ;
        //next
        node<T> * getNext() ;
        //insert
        void insert( node<T> * p ) ;
        //delete
        node<T> * delNext() ;
        // get
        node<T> * get( const T & item, node<T> * pnext = NULL) ;
    private :

        //address of next node!
        node<T> * next ;
        T data ;
} ;

template<class T>
node<T>::node() 
{
    this->data = 0 ;
    this->next = NULL ;
} 

        
template<class T>
node<T>::node( T item, node<T> *pnext ) 
{
    this->data = item ;
    this->next = pnext ;
}


#endif /* NODE */
