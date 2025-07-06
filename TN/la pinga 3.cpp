#include <bits/stdc++.h>
using namespace std;

// I saw this one
#define mx 1000006
#define ll long long
#define pb(x) push_back(x)

int gcd(ll a,ll b) {
	
	if(!b) return a;
	return gcd(b,a%b);
	
}

ll lcm(int x, int y) { 

	return x * 1ll * y / gcd(x, y); 
}


int main ( ) {

ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	
	int n,m,x,cur =1;
		cin >> n >> m;
		
	for(int i=0;i<n;i++) {
		cin >> x;
		cur = gcd( m,lcm(cur,x) )	;
	}
	if(cur == m)
		cout << "Yes";
	else
		cout << "No";
	
	
	
	
}