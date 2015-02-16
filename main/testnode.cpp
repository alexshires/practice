#include "test.hpp"
#include "node.hpp"
#include "list.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    //default class works (Makefile, linking etc)
    test<int> t1 ;
    test<int> t2(2) ;
    //default contricutor works
    node<int> a() ;
    //constructor breaks?
    node<int> b(1) ;
    node<int> c(5, &b) ;
    //
    LinkedList<int> l ;
    //todo implement testing??

    l.push_back(1) ;
    l.push_back(2) ;
    l.push_back(3) ;
    l.push_back(2) ;
    l.push_back(3) ;

    l.print() ;
    
    l.remove_dups() ;

    return 0;
}
