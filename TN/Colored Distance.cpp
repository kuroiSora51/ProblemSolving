#include <bits/stdc++.h>
using namespace std;


#define mx 1000006
#define ll long long
#define pb(x) push_back(x)


int main() {
	
int t;
	cin >> t;
	while(t--) {
		
		int n,m,k;
		ll ans;
			cin >> n >> m >> k;
		
		if(n>m)
			swap(n,m);
		
		if(k >= m)
			ans = m*n;
		if(m > k && k >= n)
			ans = n*k;
		if( n > k )
			ans = k*k;
			
		cout << ans << "\n";
	}
}