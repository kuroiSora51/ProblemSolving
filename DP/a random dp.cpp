#include <iostream>
using namespace std;

int main() {

	int t;
		cin >> t;
	while (t--) {
		
		int n;
			cin >> n;
		int h[n+1], dp[n+1];
		
		for(int i = 1; i<=n; i++) 
			cin >> h[i];	
		
		dp[n] = h[n];
		for(int x = n-1; x > 0; x--) {
			
			if ( h[x] > h[x+1] )
				dp[x] = max(dp[x+1]+1,h[x]);
			else
				dp[x] = dp[x+1] + 1;
					
		}
		
	cout << dp[1] << "\n";	
	}


}