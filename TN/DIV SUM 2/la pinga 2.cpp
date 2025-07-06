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
vector <pair<int,int>> C;
vector <pair<int,int>> D;
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

vector <pair<int,int>> Decos (int m) {
	
	vector <pair<int,int>> v;
	int root = sqrt(m);
	for(int i=0; prime[i]<=root && i<=prime.size(); i++) {
		
		if(m%prime[i] == 0) {
			
			int p = prime[i];
			int cnt = 0;
			while(m%p == 0) {
				cnt++;
				m/=p;
				
			}
		root = sqrt(m);
		v.pb( mk(p,cnt) );
		}
	}
	if (m>1)	
		v.pb( mk(m,1) );
		
	return v;
	
	
	
}

int main() {
	
	sieve(mx-1);
	int n,m;
		cin >> n >> m; 
	bool CRT = true;
	
	int c[n+1];
	for(int i=0;i<n;i++)
		cin >> c[i];
		
	for(int i=0; i<n; i++) {
		D = Decos( c[i] );
		C.insert( C.end(), D.begin(), D.end() );	
	}
	
	sort( C.begin( ), C.end() );
	
	for(int i=0; i<C.size()-1; i++) {
		
		
		if( C[i].first == C[i+1].first ) {
			
			int j = i+1;
			for(j ; j<C.size() ;j++) {
				
				if( (C[i].first != C[j].first) )
					break;
				else
					C[i].second = max( C[i].second,C[j].second );	
			}
			
			C.erase( C.begin()+i, C.begin()+j-1 );
				
		}
	}
	
	
	for(int i=0; i < n && m>1; i++) {
		
		if( m%C[i].first == 0  ) {
				
			int p = C[i].first;
			int cnt = 0;
			while(m%p == 0) {
					
				cnt++;
				m /= p;
			}
			if( C[i].second < cnt) {
				CRT = false;
				break;
			}
		}
			
	}
	
/*	for(int i=0; i<C.size(); i++) {
		
		cout << C[i].first << "^" << C[i].second << " ";
	}
*/		
	if( (m == 1) and CRT)
		cout << "Yes";
	else
		cout << "No";	
	
	return 0;
}