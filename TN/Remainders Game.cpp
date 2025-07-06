#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
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

int main( ) {

	int n,mod;
		cin >> n >> mod;
	int root = sqrt(mod);
	int c[n+1] ;
	vector < pair<int,int> > m;
	vector < pair<int,int> > P;
	
	for(int i=0; i<n; i++)
		cin >> c[i];

	for(int i = 0; i<9600 && mod>=1; i++) {
		
		if(mod%prime[i] == 0) {
			
			int ct = 1;
			int p = prime[i];
			while(mod%p == 0) {
				
				ct++;
				mod /=p;
			}
			m.pb( mk(p,ct) );
		}
	}
	
	for(int i = 0; i<n; i++) {
		
		for(int j=0; j<9600 && c[i]>=1; j++) {
			
			if(c[i]%prime[j] == 0) {
				
				int ct = 1;
				int p = prime[j];
				while(c[i]%p == 0) {
					
				    ct++;
					c[i]/=p;
				}
				P.pb( mk(p,ct) );
			}
			
		}
		
	}
	
	for(int i = 0; i<9600; i++) {
		
		for(int j =0; j<n; j++) {
			
			if( c[j]%prime[i] == 0 ) {
				
				int p = prime[i];
				int cnt = 1;
				while(c[j]%p == 0) {
					
					cnt++;
					c[j] /= p;
					
				}
				int counter = cnt;
				for(int w = j; w<n; w++) {
				
					if( c[w]%p == 0) {
						
						int cntw = 1;
						while(c[w]%p == 0) {
							
							cntw++;
							c[w] /= p;
						}
					counter = max(counter, cntw);	
					}
				
				}
				P.pb( mk(p,counter) ) ; 
			}
			
		}
	}
	
	for(int i = 0; i<m.size(); i++)
		cout << m[i].first <<" ";
		cout << m[i].second << "\n;

	cout << "\n"
	
	for(int i = 0; i<P.size(); i++) {
		cout << P[i].first << " ";
		cout << P[i].second << "\n";
	}









}