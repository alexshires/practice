#ifndef TEST
#define TEST

#include <iostream>

template<class T>
class test 
{
    public :
        test() ;
        test( T t ) ;
        
};


template class test<int> ;
template class test<double> ;
template class test<char> ;


#endif /* TEST */
