#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb(x) push_back(x)
#define N 1000000
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
		
	int notPrime[N/64 + 2];
	BwSieve(N,notPrime);	
		
	int n; cin >> n;
	while(n--){
		int x,D=1; cin>>x;
		int root = sqrt(x);
		for(int i=0;i<prime.size() && prime[i]<=root && x>1;i++){
			if(x%prime[i]==0){
				int k = 1;
				while(x%prime[i]==0){
					k++;
					x/=prime[i];
				}
				D*=k;
			}
		}
		if(x>1)
			D*=2;
		cout<<D<<"\n";
	}
		
}
	
