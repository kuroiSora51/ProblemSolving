#include <iostream>
#include <vector>

using namespace std;

long long bpow(long long a,long long b) {
 	
   if(b==0) 
   return 1;
   return ( bpow( (a * a), b /2 )*(b &1? a :1)) ;
  }
 
long long op(long long p,long long k) {
	
return	(bpow(p,k+1)-1)/(p-1);
	
}

int main () {
	
int t;cin>>t;	
	
for(int r=0;r<t;r++) {

long long n,n2,s=1,i=2;
cin>>n;
n2=n;
vector <int> pi;	
vector <int> m;
	while(n!=1) {
	 if(n%i==0) {
	 int k=0; 
	 	while(n%i==0) {
		k++;
		n/=i;
		}	
	 	 pi.push_back(i);
	   	  m.push_back(k);
	 }
	i++;
	
	}	
		for(int j=0;j<pi.size();++j) 
		
		s*=op(pi[j],m[j]) ;
		
		cout<<s-n2<<endl;
	
}
}