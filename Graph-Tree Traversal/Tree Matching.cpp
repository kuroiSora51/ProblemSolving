#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef vector<Vi> Vii;
const int MOD = 1e9+7;

struct vertex {
    int val = -1;
    int dist = 0;
    int m0 = 0, m1 = 0; //m0 <= m1
    vertex* parent = nullptr;
    vector<vertex*> adj;
};

class Tree {
    private:
        vector<vertex> vertices;
    public:
        Tree(int n) {
            vertices.resize(n);
            for (int i = 1; i <= n; i++) vertices[i-1].val = i;
        }

        void add_edge(int a, int b) {
            vertices[a-1].adj.push_back(&vertices[b-1]);
            vertices[b-1].adj.push_back(&vertices[a-1]);
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
        dfs(u);
        v->m0 += u->m1;
    }
    // compute m1
    for (vertex* u: v->adj) {
        if (u == v->parent) continue;
        v->m1 = max(v->m1, v->m0 - u->m1 + u->m0 + 1);
    }
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n;
    Tree T(n);
    
    for (int i = 2; i <= n; i++) {
        cin >> a >> b;
        T.add_edge(a, b);
    }
   
    dfs(T.root());
    cout << max(T.root()->m0, T.root()->m1);
    
    return 0;
}