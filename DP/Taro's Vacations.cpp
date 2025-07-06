#include <iostream>
using namespace std;

int main () {
	
	int n;
	cin>>n;

	
	int a[n+5],b[n+5],c[n+5];
	int va[n+5],vb[n+5],vc[n+5];
	
	for(int i=1;i<=n;i++) 	
		cin>>va[i]>>vb[i]>>vc[i];
		
	a[0]=b[0]=c[0]=0;
	a[1]=va[1];
	b[1]=vb[1];
	c[1]=vc[1];
	for(int i=2;i<=n;i++) {
		
		a[i]=va[i]+max(b[i-1],c[i-1]);
		b[i]=vb[i]+max(a[i-1],c[i-1]);
		c[i]=vc[i]+max(a[i-1],b[i-1]);	
			
	}
	int cometranca=max( a[n],max(b[n],c[n]) );
	
	cout<<cometranca;
	
}
		

	
