#include <bits/stdc++.h>
using namespace std;

#define mx 100000008
#define ll long long
#define pb(x) push_back(x)
#define TestCases(t) for(int i=0;i<t;i++)

vector <int> prime;	

void sieve (int n) {
	
	bool notPrime[n/2]={ };
	//memset(isPrime,true,sizeof(isPrime));

	int root=sqrt(n);
	for(int i=3;i<root;i+=2) {
		
		if(!notPrime[i/2])
			for(int j=i*i;j<n;j+=i+i)
				notPrime[j/2]=true;
		
	}
	prime.pb(2);
	for(int i=3;i<n;i+=2)
		if(!notPrime[i/2])
			prime.pb(i);
		
}
	
	int main () {
		
	ll r;
	cin>>r;
	sieve(r);	
		
	for(ll i=0;i<prime.size();i++) {
	
		cout<<prime[i]<<" ";	
		
}
	}