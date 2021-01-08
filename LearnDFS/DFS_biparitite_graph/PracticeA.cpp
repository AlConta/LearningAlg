// 根つき木の深さと部分木のサイズを求める

#include<iostream>
#include<vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> depth;
vector<int> subtree_size;

void dfs(const Graph& G, int v, int p, int d) { 
    depth[v] = d;

    // 子を探査
    for (auto next_v : G[v]) {
        if (next_v == p) continue; // 親はスルー
        // 親から子に情報を配る場合はここで渡す
        dfs(G, next_v, v, ++d);
    }

    //帰りがけに部分木サイズを求める(子の部分木サイズが求まっている必要があるため
    // 子の情報を吸い上げる場合はここで更新する
    subtree_size[v] = 1; // 自分自身

    for (auto c : G[v]) {
        if (c == p) continue;
        subtree_size[v] += subtree_size[c];
    }
}

int main() {
    // 頂点数N
    int N;
    cin >> N;

    Graph G(N);

    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // tree探索
    int root = 0; // 根は仮に頂点0とする
    depth.assign(N, 0);
    subtree_size.assign(N, 0);
    dfs(G, root, -1, 0);

    for (int v = 0; v < N; v++) {
        cout << v << ": depth = " << depth[v] << ", subtree_size = " << subtree_size[v] << "\n";
    }

    return 0;
}