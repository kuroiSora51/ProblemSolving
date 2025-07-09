#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> Vi;
typedef vector<Vi> Vii;
typedef pair<ll ,ll> Pii;
typedef vector<Pii> Vpii;
typedef vector<vector<bool>> grid;
const int MOD = 1e9+7;
const ll INF = LLONG_MAX / 4;

struct entry { 
   int idx; ll val;
   entry (int i, ll v) : idx(i), val(v) {}
};

struct SegTree {
   int n;
   vector<ll> st;
    
   SegTree(int _n) : n(_n) { st.assign(4 * n, INF);}
    
   // build over a[1…n]
   void build(const Vi& a, int v, int l, int r) { 
      if (l == r) {
         st[v] = a[l];
         return;
      }
      int m = (l + r) >> 1;
      build(a, v<<1, l, m);
      build(a, v<<1|1, m + 1, r);
      st[v] = min(st[v<<1], st[v<<1|1]);
   }
    
    // point update: A[idx] = val
   void update(int v, int l, int r, entry u) {
      if (l == r) {
         st[v] = u.val;
         return;
      }
      int m = (l + r) >> 1;

      if (u.idx <= m) 
         update(v<<1, l, m, u);
      else
         update(v<<1|1, m+1, r, u);

      st[v] = min(st[v<<1], st[v<<1|1]);
   }
    
   // min sum query over [i..j]
   ll min_val(int v, int l, int r, int i, int j) {
      if (j < l || r < i) return INF;          // outside
      if (i <= l && r <= j) return st[v];   // fully inside

      int m = (l + r) >> 1;
   
      return min(min_val(v<<1, l, m, i, j), min_val(v<<1|1, m+1, r, i, j));
   }
};

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int n, q, a, b, u;
   ll k;
   short int query_type;

   cin >> n >> q;

   // read original array into x[1..n]
   Vi x(n + 1);
   x[0] = INF;
   for (int i = 1; i <= n; i++) cin >> x[i];
   
   // build segment tree
   SegTree st(n);
   st.build(x, 1, 1, n);

   while (q--) {
      cin >> query_type;
      if (query_type == 2) {
         cin >> a >> b;
         cout << st.min_val(1, 1, n, a, b) << "\n";
      }
      else {
         cin >> k >> u;
         entry e(k, u);
         st.update(1, 1, n, e);
      }
   }

   return 0;
}
