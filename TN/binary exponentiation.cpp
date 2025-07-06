#include <iostream>

 using namespace std ;

 int bpow (int a , int b , int m ) {
 if( b ==0)
 return 1; 

 return ( bpow( (a * a) &m , b/2 , m ) * (b&1?a:1)) % m;
 }
 int main () {
 int a ,b , m ;
 while ( cin >>a >>b >> m ) {
 cout << POW (a ,b , m ) << endl ;
 }
 return 0;
 }
