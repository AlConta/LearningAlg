// AOJ 1160 島はいくつあるか？

#include<iostream>
#include<vector>
using namespace std;

int H, W;
vector<vector<int>> field;

void dfs(int h, int w) {
    field[h][w] = 0;

    //八方向を探索
    for (int dh = -1; dh <= 1; dh++) {
        for (int dw = -1; dw <= 1; dw++) {
            int nh = h + dh;
            int nw = w + dw;
            //場外,0はスルー
            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if (field[nh][nw] == 0) continue;

            //再帰的に探索
            dfs(nh, nw);
        }
    }

}

int main() {

    while (cin >> W >> H) {
        if (H == 0 || W == 0) break;
        field.assign(H, vector<int>(W,0));

        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                cin >> field[h][w];
            }
        }

        int count = 0;
        for (int h = 0; h < H; h++) {
            for (int w = 0; w < W; w++) {
                if (field[h][w] == 0) continue; //踏破済みはスルー

                dfs(h,w);
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}
