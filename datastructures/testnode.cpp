
#include "node.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    Node<int> a ;
    Node<int> b(1, NULL) ;
    Node<int> c(5, &b) ;

    //todo implement testing??

    return 0;
}
