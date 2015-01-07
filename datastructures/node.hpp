// templated linked list

#include <iostream>

template<class T> 
class Node
{
    public : 
        Node() ; //default cosntructor
        //real cosntructor
        Node( const T & item, Node<T> *pnext = NULL ) ;
        //next
        Node<T> * getNext() ;
        //insert
        void insert( Node<T> * p ) ;
        //delete
        Node<T> * delNext() ;
        // get
        Node<T> * get( const T & item, Node<T> * pnext = NULL) ;
    private :

        //address of next node!
        Node<T> * next ;
        T data ;
} ;
