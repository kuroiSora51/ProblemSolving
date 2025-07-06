#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define p 1000000007
#define ll long long

ll bPow(ll a , ll b) {
	a%=p;
	if(b==0)
 		return 1; 
	return ( (bPow( (a*a)%p , b/2)%p) * (b&1?a:1) ) % p;
}

ll inv(ll x){
	return bPow(x,p-2);
}

ll modSqrt(ll x){
	return bPow(x,(p+1)/4);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n; cin>>n;
	int x[n];
	ll k[n],dsum=1, psum=1, divs=1,exp=1;
	for(int i=0;i<n;i++)
		cin>>x[i]>>k[i];
	for(int i=0;i<n;i++){
		ll Vp = bPow(x[i],k[i]+1);
		
		divs *= k[i]+1;
		divs %= p;
		dsum *= ( (Vp-1)*inv(x[i]-1) )%p;
		dsum %= p;
		psum = bPow(psum,k[i]+1)*
		           bPow(bPow(x[i], (k[i] * (k[i] + 1) / 2)), exp) % p;
		exp *= (k[i]+1);
		exp %= p-1;
	}
	
		
	cout<<divs<<" "<<dsum<<" "<<psum<<"\n";
}