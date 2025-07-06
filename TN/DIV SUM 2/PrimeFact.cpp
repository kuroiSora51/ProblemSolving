#include <bits/stdc++.h>
using namespace std;
typedef vector<pair<int,int>> Vpii;
#define pb(x,y) push_back({x,y})

void primeFact(int n) {
   Vpii factors;
   
   for(int p = 2; p * p <= n; ++p) {
      if (n % p) continue;
      int k=0;
      while (n % p == 0) {
         n /= p; k++;
      }
      factors.pb(p,k);
   }
   if (n > 1) factors.pb(n,1);
   for (auto [p,k] : factors) 
      cout << p << "^" << k << " ";
}

int main() {
   int n; cin >> n;
   primeFact(n);
}