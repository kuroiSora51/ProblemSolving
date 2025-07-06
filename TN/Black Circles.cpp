#include <bits/stdc++.h>
using namespace std;

#define mx 1000000009
#define ll long long
#define pb(x) push_back(x)
#define x  first
#define y  second


ll dis( pair<ll,ll> s, pair<ll,ll> t ) {
	
	ll ans = (s.x-t.x)*(s.x-t.x) + (s.y-t.y)*(s.y-t.y) ;
	
	return ans;
}

int main ( ) {

ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int t;
	cin >> t;

	while(t--)  {
		
		int n;
			cin >> n;
		pair <int,int> c[n], s, t;
		
		for(int i=0; i<n; i++)
			cin >> c[i].x >> c[i].y;
		
		cin >> s.x >> s.y;
		cin >> t.x >> t.y;
		
		ll Dct = LLONG_MAX, Dst = 0;
		
		for(int i=0; i<n; i++) {
			
			Dct = min( Dct , dis( c[i], t ) );
		}
		Dst = dis(s,t);
		
		
		if( Dst < Dct )
			cout << "YES"<<"\n";
		else
			cout << "NO"<<"\n";
		
		
		
	}


}