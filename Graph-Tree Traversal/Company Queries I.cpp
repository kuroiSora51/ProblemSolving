#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef vector<Vi> Vii;
const int MOD = 1e9+7;

struct vertex {
    int val = -1;
    int dist = 0;
    vertex* parent = nullptr;
    vector<vertex*> adj;

    vertex* climb_until (int k);
};

class Tree {
    public:
        vector<vertex> vertices;
        Tree(int n) {
            vertices.resize(n);
            for (int i = 1; i <= n; i++) vertices[i-1].val = i;
        }

        void add_edge(int a, int b) {
            vertices[a-1].adj.push_back(&vertices[b-1]);
        }
        
        auto root() {return &vertices.front();}
        auto begin() { return vertices.begin(); }
        auto end() { return vertices.end(); }
        auto begin() const { return vertices.begin(); }
        auto end() const { return vertices.end(); }
};

// v.parent -> v -> u
void dfs (vertex* v) {
 
    for (vertex* u : v->adj) {
        if (u == v->parent) continue;
        u->parent = v;
        u->dist = v->dist + 1;
        dfs(u);
    }
}

vertex* vertex::climb_until (int k) {
    vertex* kth_boss = this;

    while(k--){
        kth_boss = kth_boss->parent;
    }
    return kth_boss;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, boss, x_val, k;
    cin >> n >> q;
    Tree T(n);
    
    for (int i = 2; i <= n; i++) {
        cin >> boss;
        T.add_edge(boss, i);
    }
   
    dfs(T.root());
    
    while (q--) {
        cin >> x_val >> k;
        vertex* x = &T.vertices[x_val-1];
        if (x->dist < k) cout << -1;
        else {
            vertex* ans = x->climb_until(k);
            cout << ans->val;
        }
        cout << '\n';
    }
    
    return 0;
}