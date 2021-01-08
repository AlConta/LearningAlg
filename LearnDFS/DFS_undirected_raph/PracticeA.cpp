//無向グラフGの連結成分の個数を求める
// 連結成分：任意の二頂点間にパスが存在する部分グラフのうち極大のもの(幹になるもの
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
    // 頂点数N, 辺数M
    int N, M;
    cin >> N >> M;

    Graph G(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false);

    // 全頂点が探索済みになるまで探索
    int count = 0;
    for (int v = 0; v < N; v++) {
        if (seen[v]) continue;
        dfs(G, v);
        ++count;
    }   

    // 探査開始回数=連結成分の個数
    cout << count << "\n";

    return 0;
}
