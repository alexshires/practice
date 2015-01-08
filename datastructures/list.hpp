#ifndef LINKEDLIST
#define LINKEDLIST

template<class T>
struct node
{
    T data ;
    node<T> *pnext ;
} ;





template<class T>
class LinkedList
{
    public :
        //constructors
        LinkedList() ;
        LinkedList(T val, int size) ;

        // basic methods
        void push_back( const node<T> & n ) ;
        void delete_node( const node<T> & n ) ;
        void print() ;
        void clear() ;
    
        //advanced emthods

    private :

        node<T> root ;
}


#endif /*  */
