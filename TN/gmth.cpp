#include <bits/stdc++.h>
using namespace std;


#define mx 1000006
#define ll long long
#define pb(x) push_back(x)


int main() {
	
int t;
	cin >> t;
	while(t--) {
		
		int n;
			cin >> n; 
		int a[n],b[n];
		bool normal=true,inverted=true;
		
		for(int i=0;i<n;i++)
			cin >> a[i];
			
		for(int i=0;i<n;i++)
			cin >> b[i];
		
		for(int i=0;i<n;i++) {
			
			if(a[i] == b[i])
				normal = normal and true;
			else
				normal = false;
				
				
		}
		for(int i=0;i<n;i++) {
			
			if(a[i] == b[n-i-1])
				inverted = inverted and true;
			else
				inverted = false;
		}
		if(normal or inverted)	
			cout << "Bob\n";
		else
			cout << "Alice\n";
	}
	
}