#include <bits/stdc++.h>
using namespace std;

#define mx 500000
#define ll long long
#define pb(x) push_back(x)
#define inv(x) bpow(x,m-2,m)
#define in(x) bpow(x,m1-2,m1)
#define x  first
#define y  second

const int m = 1e9+9;
const int m1 = 1000000123;
const int p = 31;
vector <ll> Vp;
vector <ll> Vp1;
vector <ll> H;
vector <ll> inp;
vector <ll> inp1;
vector <ll> H1;

ll bpow(ll a, ll b, ll mod) {
 if(b==0) return 1;
 if(a==1) return 1;
 
 return 
 ((bpow(a*a%mod,b/2,mod)%mod)*(b&1?a:1)%mod)%mod ;
}
ll Hash(string & s,ll mod) {

	ll Vp = 1;
    ll Hash = 0;
    for (char c : s) {
        Hash = (Hash + (c - 'a' + 1) * Vp) % mod;
		Vp = (Vp*p)%mod;
    }
    return Hash;
    
}

int main ( ) {

 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	//declarations
	string S,W;
		cin >> S >> W;
	int n = S.size();
	int z = W.size();
	int end = n-z+1;
	int counter = 0, counter1 = 0;
	
	// the first p^k
		Vp.pb(1);
	for(int i=1; i<n; i++) {
		int q = (Vp[i-1]*p)%m;
		Vp.pb(q);
	}
	
	// the first p^-k
		ll inverse = inv(p);
		inp.pb(1);
		inp.pb(inverse);
	for(int i=2;i<n;i++) {
		
		ll q = (inp[i-1]*inverse)%m;
		inp.pb(q);
	}
	
	
	// the first hashing
	int base_case = S[0] - 'a' + 1;
	H.pb(base_case);
	
    for (int k=1; k<n; k++) {
		
        H.pb ( (H[k-1] + (S[k] - 'a' + 1) * Vp[k]) % m );
    
	}
	ll Hw = Hash(W,m);
	
	//the first counting
	if( H[z-1] == Hw )
		counter++;
	
	for(int i=1;i<end;i++) {
		
		ll Hs = ( (H[i+z-1]-H[i-1])%m + m) %m;
		Hs = (Hs*inp[i])%m ;
		if(Hs == Hw)
			counter++;

	}
		// the second p^k
		Vp1.pb(1);
	for(int i=1; i<n; i++) {
		int q = (Vp1[i-1]*p)%m1;
		Vp1.pb(q);
	}
	
	// the second p^-k
		ll inverse1 = in(p);
		inp1.pb(1);
		inp1.pb(inverse1);
	for(int i=2;i<n;i++) {
		
		ll q = (inp1[i-1]*inverse1)%m1;
		inp1.pb(q);
	}
	
	
	// the second hashing
	int base_case1 = S[0] - 'a' + 1;
	H1.pb(base_case1);
	
    for (int k=1; k<n; k++) {
		
        H1.pb ( (H1[k-1] + (S[k] - 'a' + 1) * Vp1[k]) % m1 );
    
	}
	ll Hw1 = Hash(W,m1);
	
	//the second counting
	if( H1[z-1] == Hw1 )
		counter1++;
	
	for(int i=1;i<end;i++) {
		
		ll Hs1 = ( (H1[i+z-1]-H1[i-1])%m1 + m1) %m1;
		Hs1 = (Hs1*inp1[i])%m1 ;
		if(Hs1 == Hw1)
			counter1++;

	}
	
	
	cout << min(counter,counter1);


	return 0;
}