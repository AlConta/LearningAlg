//有向グラフGの二頂点s,t∈Vが与えられたとき、sから辺をたどってtに到達できるか判定
#include<iostream>
#include<vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;

void dfs(const Graph& G, int v) {
    seen[v] = true;

    for (auto next_v : G[v]) {
        if (seen[v]) continue;
        dfs(G, next_v);
    }
}

int main() {
    // 頂点数N, 辺数M, s,t
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    Graph G(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    
    seen.assign(N, false);

    // 頂点sをスタートとした探索
    dfs(G, s);

    // tに辿り着いた?
    if (seen[t]) cout << "true\n";
    else  cout << "true\n";
    
    return 0;
}
