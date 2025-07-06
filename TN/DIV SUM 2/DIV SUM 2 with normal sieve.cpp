#include <bits/stdc++.h>
using namespace std;

#define mx 100000008
#define ll long long
#define pb(x) push_back(x)
#define TestCases(t) for(int i=0;i<t;i++)

vector <int> prime;	

void sieve (int n) {
	
	bool isPrime[n/2];
	memset(isPrime,true,sizeof(isPrime));

	int root=sqrt(n);
	for(int i=3;i<root;i+=2) {
		
		if(isPrime[i/2])
			for(int j=i*i;j<n;j+=i+i)
				isPrime[j/2]=false;
		
	}
	prime.pb(2);
	for(int i=3;i<n;i+=2)
		if(isPrime[i/2])
			prime.pb(i);
		
}
	
	int main () {
		

	sieve(1000000);
	int t;
	cin>>t;
	
	TestCases(t) {
	ll n;
	cin>>n;	
	int root=sqrt(n);
	ll dsum=1;
	for(int i=0;i<prime.size() && prime[i]<=root;i++) {
	int why=prime[i];
		if(n%prime[i]==0) {
		int Vp=prime[i];
		while(n%prime[i]==0) {
			
			Vp*=prime[i];
			n/=prime[i];
			
		}
		dsum*=(Vp-1)/(prime[i]-1);	
		root=sqrt(n);
	}
}
 
  dsum=(dsum>1)?(dsum)*(n+1):dsum;
  
  cout<<dsum;	
		
	 
	
		
		
		
		
		

}
}
