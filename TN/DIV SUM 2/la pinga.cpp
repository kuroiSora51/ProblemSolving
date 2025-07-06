#include <bits/stdc++.h>
using namespace std;

#define mx 1000006
#define ll long long
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define fill(n,m) memset(n, m, sizeof(n) )

#define noes(x) ( notPrime[x/64] & (1<<( (x&63)>>1)) ) 
#define mark(x) ( notPrime[x/64] |=(1<<( (x&63)>>1)) )

vector <int> prime;
int notPrime [mx/64 + 2];
void sieve (int n) {

	
	//fill(notPrime,0); 
 
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
			int why=i;
			prime.pb(i);
		}
}

}


void Decos (vector <pair<int,int>> v, int m) {
	
	for(int i=0; prime[i]<=m; i++) {
		
		if(m%prime[i] == 0) {
			
			int p = prime[i];
			int cnt = 0;
			while(m%p == 0) {
				cnt++;
				m/=p;
				
			}
		v.pb( mk(p,cnt) );	
		}
	}
	
	
	
}

int main() {
	
	
 	sieve(mx-1);
	
	int n;
		cin >> n; 
	vector <pair<int,int>> N;

	
	Decos(N, n);
	
	int r = N.size();
	cout << r;
	

	
	
	return 0;
}