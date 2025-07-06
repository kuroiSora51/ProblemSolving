#include <iostream>
#define ll long long
#define p 1000000007
using namespace std ;

ll bpow(ll a , ll b) {
	a%=p;
	if(b==0)
 		return 1; 
	return ( (bpow( (a*a)%p , b/2)%p) * (b&1?a:1) ) % p;
 }
 int main () {
 	ll n,a,b; 
 	cin>>n;
 	while(n--){
 		cin>>a>>b;
 		cout << bpow(a,b) << endl ;
	 }
	
 
 	return 0;
 }
