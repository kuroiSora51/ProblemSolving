#include <iostream>
#include <algorithm>
#define maxn 1000000
using namespace std;


	int n,k;
	long long v[maxn];
	long long cache[maxn];
	
	void fill(int n) {
		
		for(int i=0;i<=n;i++)
		cache[i]=-1;
		return;
	}
	
	
long long dp(int x) {
	
	if(x==n) return cache[x]=v[n];
	if (cache[x] != -1) return cache[x];
  	long long op1=dp(x+1)+v[x];
	long long op2=dp( x+((n-x+1)/2) )+k;
	return (  cache[x] = min(op1,op2)  );

	
}	  
	
int main () {
	
	cin>>n>>k;
	fill(n);
	v[0]=cache[0]=0;
	for(int i=1;i<=n;i++)
	cin>>v[i];
		sort(v,v+n+1);
	
	cout<<dp(1);
	
	
	return 0;
}	