#include <bits/stdc++.h>
using namespace std;

#define mx 100000008
#define pb(x) push_back(x)
#define noes(x) ( notPrime[x/64] & (1<<( (x&63)>>1)) ) 
#define mark(x) ( notPrime[x/64] |=(1<<( (x&63)>>1)) )
typedef long long ll;

const ll MAX = 1e10;
const ll MIN = 1e9;
const int P_max = sqrt(MAX);
const int Q_max = cbrt(MAX);
vector <int> prime;
int notPrime [mx/64 + 2];

void sieve(int n){
 
   int root=sqrt(n);	
   for(int i=3;i<root;i+=2) {
   		if ( !noes(i) ) {
   			for(int j=i*i,k=i<<1;j<=n;j+=k)
   				mark(j);
			}
	}
   	prime.pb(2);  
	for(int i=3;i<n;i+=2) {
		if(!noes(i)) {
			prime.pb(i);
		}
	}

}

ll bpow(ll a , ll b, ll m) {
	a%=m;
	if(b==0)
 		return 1; 
	return ( (bpow( (a*a)%m , b/2, m)%m) * (b&1?a:1) ) % m;
 }

int property(const ll& p){
	ll P = p*p;
	ll Q = bpow(2, p-1, P);
	if (Q % P == 1) return p;
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	vector <int> ans;
	sieve(mx-1);
	int n = prime.size();
	ll cnt = 0;
	for(int i=0; prime[i]<P_max; ++i){
		int p = prime[i];
		int chosen = property(p);
		if (!chosen) continue;
		ans.pb(chosen);
		++cnt;
	}
	cout<<cnt<<'\n';
	for(int p : ans) cout << p << ' ';

}
