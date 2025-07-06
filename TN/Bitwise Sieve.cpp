#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb(x) push_back(x)
#define TestCases(t) for(int i=0;i<t;i++)
#define fill(n,m) memset(n, m, sizeof(n) );

#define noes(x) ( notPrime[x/64] & (1<<( (x&63)>>1)) ) 
#define mark(x) ( notPrime[x/64] |=(1<<( (x&63)>>1)) )

vector <int> prime;
void BwSieve (ll n,int notPrime[]) {
 
 
   int root=sqrt(n);	
   for(int i=3;i<root;i+=2)	{
   
   	
   		if ( !noes(i) )  {
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
	int main () {
		
	ll r;
	cin>>r;
	int notPrime[r/64 + 2];
	BwSieve(r,notPrime);
	for(ll i=0;i<prime.size();i++) {	
		cout<<prime[i]<<" ";
	}
}
