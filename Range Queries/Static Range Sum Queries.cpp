#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> Vi;
typedef vector<Vi> Vii;
typedef pair<ll ,ll> Pii;
typedef vector<Pii> Vpii;
typedef vector<vector<bool>> grid;
const int MOD = 1e9+7;
const ll INF = LLONG_MAX;


int main () {
   cin.tie(0)->sync_with_stdio(0);

   int n, q, a, b;
   cin >> n >> q;

   ll x[n + 1], sum[n + 1];
   x[0] = sum[0] = 0;

   for (int i = 1; i <= n; i++) {
      cin >> x[i];
      sum[i] = sum[i - 1] + x[i];
   }

   while (q--) {
      cin >> a >> b;
      cout << sum[b] - sum[a - 1] << '\n';
   }


   return 0;
}