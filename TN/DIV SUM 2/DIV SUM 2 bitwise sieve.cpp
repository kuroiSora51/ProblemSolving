#include <bits/stdc++.h>
using namespace std;

#define mx 100000008
#define ll long long
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define TestCases(t) for(int i=0;i<t;i++)
#define fill(n,m) memset(n, m, sizeof(n) )

#define noes(x) ( notPrime[x/64] & (1<<( (x&63)>>1)) ) 
#define mark(x) ( notPrime[x/64] |=(1<<( (x&63)>>1)) )

vector<int> prime;
int notPrime [mx/64 + 2];
void sieve (int n) {
   int root=sqrt(n);

   for(int i=3;i<root;i+=2) {
      if (noes(i)) continue;
      for(int j=i*i,k=i<<1;j<=n;j+=k)
         mark(j);
   }

   prime.pb(2);   
	for(int i=3;i<n;i+=2) 
		if(!noes(i)) prime.pb(i);
}


int main() {
	
 int t;
 cin>>t;
 	sieve(mx-1);
	TestCases(t) {
	ll n,dsum=1; 
	cin>>n;	
	int root=sqrt(n);
	ll m=n;
	
		
	for(int i=0;i<prime.size() && prime[i]<=root;i++) {
		
		if(n%prime[i]==0) {
			int p=prime[i];
			ll Vp=p;
			while(n%p==0) {
			Vp*=p;	
			 n/=p;		
			
			}
			dsum*=(Vp-1)/(p-1);
			root=sqrt(n);	
		}
	}	
		
	if(m==1) dsum=0;
	else if(n==1) dsum-=m;
	else dsum=dsum*(n+1)-m;
	cout<<dsum<<endl;



	} 		
	return 0;
}