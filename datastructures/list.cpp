#include "list.hpp"

template<class T>
LinkedList<T>::LinkedList(T val) 
{
    root = new node<T>(val,NULL) ;
}

template<class T>
void LinkedList<T>::push_back( const T t ) 
{
    node<T> *  tmpnode = new node<T>(t,root);
}



