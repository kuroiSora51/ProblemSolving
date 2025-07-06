#include <iostream>
#include <tuple>        
using namespace std;
 

tuple<int, int, int> extended_gcd(int a, int b)
{
    if (a == 0) {
        return make_tuple(b, 0, 1);
    }
 
    int gcd, x, y;
 
    
    tie(gcd, x, y) = extended_gcd(b % a, a);
 
    return make_tuple(gcd, (y - (b/a) * x), x);
}
 
int main()
{
    int a,b,c ;
   
    cin>>a>>b>>c;
    if(a==0 && b==0) {
	
    cout<<"no asere";
    }

    tuple<int, int, int> t = extended_gcd(a, b);
 
    int g = get<0>(t);
    int x = get<1>(t);
    int y = get<2>(t); 
    
   	if(c%g)  {
	cout<<"no asere";
 	return 0; }
    
   		x*=c/g;
       	y*=c/g;
 		g=abs(g);
 		
  		 cout << "el mcd es " <<g<< endl;
    //	cout << "x = " << x << " y = " << y << endl;
    //	cout << a << "*" << x << " + " << b << "*" << y << " = " << c << endl; 
 
     //   cout << "x = " << x <<"+"<<b/g<<"*k"<<endl;
     //   cout << "y = " << y <<"-"<<a/g<<"*k"<<endl;
        
        if(y>x) {
        	swap(x,y);
        	swap(a,b);
		}
        
        
        int a1=a/g;
        int b1=b/g;
        
        while(y<0) {
        	
         y+=a1;
		 x-=b1;
		   	    
		if(x<0) {
    		cout<<"no asere";
    		return 0;
				}
	    
        	}
		
		cout << "x = " << x << " y = " << y << endl;
    	cout << a << "*" << x << " + " << b << "*" << y << " = " << c << endl; 	
 
    return 0;
}
