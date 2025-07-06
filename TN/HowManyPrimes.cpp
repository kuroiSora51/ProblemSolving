#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb(x) push_back(x)
#define TestCases(t) for(int i=1;i<=t;i++)
#define fill(n,m) memset(n, m, sizeof(n) );
#define mx 50000007
#define len 884
#define mxx 781250

#define noes(x) ( notPrime[x>>6] & (1<<( (x&63)>>1)) ) 
#define mark(x) ( notPrime[x>>6] |=(1<<( (x&63)>>1)) )


int notPrime[mxx];
int counter [mxx] = { };
int Sqcounter [len] = { };
void BwSieve (ll n) {
 
 
   int root=sqrt(n);	
   for(int i=3;i<root;i+=2)	{
   
   	
   		if ( !noes(i) )  {
   			for(int j=i*i,k=i<<1;j<=n;j+=k)
   				mark(j);
   		}
   }

	counter[0]=18;      
		for(int i=65;i<n;i+=64) {
			for(int j=i,aux=j+64;j<aux;j+=2) {
			
				counter[i>>6]=counter[i>>6 - 1]; 
				if(!noes(j)) 
					counter[j>>6]++;	
		
			}
		}
}



int HowMany(int a,int b) {
	
//Casos Base--------------------------------------------------------------------------
	if(!(a&1)&&(a==b)&&(a!=2)) return 0;
	if(a>b) return 0;
	
	int c=0;
	if(a<3) {
		switch (b) {
			case 1:
				return 0;	
			case 2:
				return 1;
			case 3:
				return 2;
			case 4:
				return 2;		
			default:
				a=3; c++;	
		}
	}
	
		
	a=a&1?a:a+1;
	b=b&1?b:b-1;	
		
	
	if (a==b) return(!noes(a))	;	

//Ordenamiento de a y b--------------------------------------------------------	
	int a1=(a>>6 + 1)<<6;
	for(int i=a;i<a1;i+=2) 
			if(!noes(i)) 
				c++;
					
	int	b1=(b>>6)<<6;
	for(int i=b;i>b1;i-=2)
		if(!noes(i))
			c++;
	
	if(a-b<63) 
		return c-counter[a>>6];	
	else
		c+=counter[(b>>6)-1]-counter[a>>6];
			
		
/*Sqrt Descomposition-----------------------------------------------------------------	
		for(int i=0;i<mxx;i++) 
		Sqcounter[i/834]+=counter[i];		
			
	int	l=a/64 + 1 , r=b/64;
	int	cl=l/len, cr=r/len ;		
			
	if(cl==cr)
		for(int i=l;i<r;i++)	
			c+=counter[i];
	else{
		for(int i=l,aux=(cl+1)*len-1;i<aux;i++)
			c+=counter[i];
		for(int i=cl+1;i<cr-1;i++)
			c+=Sqcounter[i];
		for(int i=cr*len;i<r;i++)
			c+=counter[i];
	}
		
*/		
		
		
	
	return c;	
}

	int main () {
		
	BwSieve(mx-7);	
	
	int t;
	cin>>t;	

	TestCases(t) {
	
	int a,b;
	cin>>a>>b;	
	cout<<"Test Case #"<<i<<": "<<HowMany(a,b)<<endl;	
		
		
	}

	
}
	
