#include <iostream>
#define ll long long
#define lcm(a,b) a*b/gcd(a,b)

ll gcd(ll a,ll b) {
	
	if(!b) return a;
	return gcd(b,a%b);
	
}



int main () {
	
	ll a,b;
	std::cin>>a>>b;
	std::cout<<gcd(a,b)<<" ";
	std::cout<<lcm(a,b);
	
}