#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb(x) push_back(x)
#define m 1000000007
#define mx 200005
#define inv(x) bpow(x,m-2)

ll bpow(ll a, ll b) {
 if(b==0) return 1;
 if(a==1) return 1;
 
 return 
 ((bpow(a*a%m,b/2)%m)*(b&1?a:1)%m)%m ;
}

vector <ll> fact;
		
ll nCr(ll n, ll k) {
	if(k>n) return 0;
	
	if(k<0 or n<0)
		return 0;
	if(k==0 or n==0)
		return 1;
		
	ll ans=1;
	ll f1 = fact[n];
	ll f2 = inv( fact[n-k] ) ;
	ll f3 = inv( fact[k] ) ;
		
	ans= ((((f1*f2)%m)*f3)%m) ;	
	return ans;
}

int main ( ) {

ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

fact.pb(1);
for(int i=1; i<mx;i++) {
	ll p = fact[i-1]*i;
	fact.pb( p%m );

}
int t;
	cin >> t;
	
	while(t--) {
		
		int n, k, k1, a=0,b=0, ans = 0;
		bool x;	
			cin >> n >> k;
		for(int i=0; i<n ;i++) {
			
			cin >> x;
			if(x)
				b++;
			
		}
		
		a = n-b;
		k1 = (k+1)/2;
		
		for(int i = max(k1-a-1,0); i<=min(k1-1,b-k1) ;i++) {
		
			ans += ( nCr(b,k1+i)*nCr(a,k1-i-1) )%m ;
			ans = ans%m;
		}
		cout << ans << "\n";

		
	}
	return 0;
}