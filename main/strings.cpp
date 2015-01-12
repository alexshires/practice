//string manipulation
//
//
#include <iostream>
#include <string>


bool unique(const char * c, const int n)
{
    //linear - needs hash function , if size > 2, quit.
    /*char * letters[26];
    for ( int i =0 ; i < n ; ++i )
    {

    }*/
    // squared (max)
    bool u = false ;
    for ( int i = 0 ; i < n -1 ; i++ )
    {
        for ( int j = i + 1 ; j < n ; ++j )
        {
            //std::cout << c[i]<< '\t' <<  c[j] << std::endl ;
            if (c[i] == c[j]) {
                return true ;
            }
        }
    }
    return u ;
}



void reverse( char * c, char * r)
{
    //find size
    int i = 0 ;
    while ( c[i] != '\n' )
    {
        ++i ;
    }
    int n = i ;
    //
    if (r == NULL)  r = new char[n] ;
    for ( int i=0 ; i < n ; ++i )
    {
        r[n-i-1] = c[i] ;
    }
    for ( int i=0 ; i < n ; ++i )
    {
        std::cout << i << '\t' << c[i] << '\t' << "r " << r[i] << std::endl ;
    }
    return ;
}



int main(int argc, char *argv[])
{
    char c1[] = "abc\n" ; 
    char c2[] = "aabc\n" ;
    std::cout << unique( c1, 3) << std::endl ;
    std::cout << unique( c2, 4) << std::endl ;
    char * r1 = NULL ;
    reverse( c1, r1) ;
    r1 = NULL ;
    reverse( c2, r1) ;

    return 0;
}


