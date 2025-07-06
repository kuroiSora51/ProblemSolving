#include <iostream>
#include <math.h>
#include <vector>
#define max 1000000000
using namespace std;

long long c[max+1];
vector <int> a;

void criba() {
	
for(long long i=0;i<=max;i++) c[i]=i;
	
c[0]=c[1]=0;	

   for(long long i=2;i*i<=max;i++) 
   if (c[i]==i)
 for(long long j=i+i;j<=max;j+=i) 
 c[j]=i;	
  
	
}

long long ps(long long p,long long k) {

long long s=(pow(p,k+1)-1)/(p-1);

/*int s=0;
   for(int r=0;r<=k;r++) 
s+=pow(p,r); */
return s ;
}

void fp(long long n) {		
		
if (n<=1) return;
long long k=1;
long long m=n/c[n];	
while (c[n]==c[m]) {
	
k++;
m=m/c[m];	
}
fp(m);
a.push_back(c[n]);
a.push_back(k);
}



int main () {
long long t;
cin>>t;
for(long long i=0;i<t;i++) {
	
	long long n,k,sum=1;
	cin>>n;
	criba () ;	
		
	fp(n);
	for(long long i=0;i<a.size();i+=2) 
	sum*=ps(a[i],a[i+1]) ;
	
	cout<<sum-n<<endl;
	}
return 0;
}