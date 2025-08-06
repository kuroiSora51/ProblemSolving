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

struct point{int x, y;};
istream& operator>>(istream& in, point& p) {
    return in >> p.x >> p.y;
}


int main () {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    point p1, p2;
    char c;
    cin >> n >> q;

    // sum[x][y] goes from (1,1) to (x,y)
    int sum[n + 1][n + 1] = {0};
    bool x[n + 1][n + 1] = {false};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            x[i][j] = (c == '*');
        }  
    } 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] 
                      - sum[i - 1][j - 1] 
                      + static_cast<int>(x[i][j]);
        }
    }
    
    while (q--) {
        cin >> p1 >> p2;
        ll ans = sum[p2.x][p2.y]
               - sum[p1.x - 1][p2.y] - sum[p2.x][p1.y - 1]
               + sum[p1.x - 1][p1.y - 1];
        cout << ans << '\n';
   }
   return 0;
}