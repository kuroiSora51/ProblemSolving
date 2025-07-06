#include <iostream>
#define ll long long
#define p 1000000007
using namespace std ;

ll bPow (ll a , ll b,ll m) {
	a%=m;
	if(b==0)
 		return 1; 
	return ( (bPow( (a*a)%m , b/2, m)%m) * (b&1?a:1) ) % m;
 }
 int main () {
 	int n,a,b,c; 
 	cin >> n;
 	while(n--){
 		cin >> a >> b >> c;
	 	ll exp = bPow(b,c,p-1);
	 	ll ans = bPow(a,exp,p);
	 	cout<<ans<<"\n";
	 }
	
 
 	return 0;
 }
