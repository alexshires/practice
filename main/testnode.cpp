#include "test.hpp"
#include "node.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    //default class works (Makefile, linking etc)
    test t ;
    //default contricutor works
    Node<int> a() ;
    //constructor breaks?
    Node<int> b(1, NULL) ;
    Node<int> c(5, &b) ;

    //todo implement testing??

    return 0;
}
