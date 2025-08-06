#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> Vi;
typedef vector<Vi> Vii;
const int MOD = 1e9+7;

struct vertex {
    int val = -1;
    int cnt = 1;
    vertex* parent = nullptr;
    vector<vertex*> adj;

    bool operator>(const vertex& other) const {return this->val > other.val;}
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
        }
};

// v.parent -> v -> u
void dfs (vertex* v) {

    for (vertex* u: v->adj) {
        if (u == v->parent) continue;
        u->parent = v;
        dfs(u);
        v->cnt += u->cnt;
    }
}

int main () {
    int n, boss;
    cin >> n;
    Tree T(n);
    
    for (int i = 2; i <= n; i++) {
        cin >> boss;
        T.add_edge(boss, i);
    }

    dfs(&T.vertices[1]);

    for (int i = 1; i <= n; i++)
        cout << T.vertices[i].cnt - 1 << ' ';
}