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
};

class Tree {
    public:
        vector<vertex> vertices;
        Tree(int n) {
            vertices.resize(n + 1);
            for (int i = 1; i <= n; i++) vertices[i].val = i;
        }
        void add_edge(int a, int b) {
            vertices[a].adj.push_back(&vertices[b]);
            vertices[b].adj.push_back(&vertices[a]);
        }
        void clear_dist() {
            for (vertex& v: vertices) v.dist = 0;
        }
};

// v.parent -> v -> u
void dfs(vertex* v, vertex*& furthest) {
    if (v->dist > furthest->dist) 
        furthest = v;
    
    for (vertex* u : v->adj) {
        if (u == v->parent) continue;
        u->parent = v;
        u->dist = v->dist + 1;
        dfs(u, furthest);
    }
}

vertex* find_furthest(vertex* v) {
    v->parent = nullptr;
    vertex* furthest = v;
    dfs(v, furthest);

    return furthest;
}

int main () {
    int n, a, b;
    cin >> n;
    Tree T(n);
    
    for (int i = 2; i <= n; i++) {
        cin >> a >> b;
        T.add_edge(a, b);
    }

    vertex* start = &T.vertices[1];
    vertex* mid = find_furthest(start);
    T.clear_dist();
    vertex* end = find_furthest(mid);

    cout << end->dist;
}