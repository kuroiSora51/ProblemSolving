#include <iostream>
#define ll long long
#define p 1000000007
using namespace std ;

ll bpow(ll a , ll b, ll m) {
	a%=p;
	if(b==0)
 		return 1; 
	return ( (bpow( (a*a)%p , b/2, m)%p) * (b&1?a:1) ) % p;
 }
 int main () {
 	ll q,b; 
	cin>>q>>b;
 	cout << bpow(q,b,p) << endl ;
 
 	return 0;
 }
