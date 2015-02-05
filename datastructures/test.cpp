
#include "test.hpp"

template<class T>
test<T>::test()
{
    std::cout << "test " << std::endl ;
}

template<class T>
test<T>::test( T t)
{
    std::cout << "test " << t << std::endl ;
}



