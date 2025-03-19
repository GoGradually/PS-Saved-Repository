#include <bits/stdc++.h>
#define ll long long
#define INF ((int)1e9 + 10)

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int hx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    int n, m;
    cin >> m >> n;
    int arr[201][201];
    int check[201][201][31];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int t = 0; t <= k; t++) {
                check[i][j][t] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    queue<tuple<int, int, int>> bfsQ;
    bfsQ.push({0, 0, 0});
    check[0][0][0] = 0;
    while (!bfsQ.empty()) {
        auto now = bfsQ.front();
        bfsQ.pop();
        int x, y, count;
        tie(x, y, count) = now;
        for (int i = 0; i < 4; i++) {
            int p = x + dx[i], q = y + dy[i];
            if (arr[p][q] == 1) continue;
            if (p < 0 || p >= n || q < 0 || q >= m) continue;
            if (check[p][q][count] != -1) continue;
            bfsQ.push({p, q, count});
            check[p][q][count] = check[x][y][count] + 1;
        }
        for (int i = 0; i < 8; i++) {
            int p = x + hx[i], q = y + hy[i];
            if (arr[p][q] == 1) continue;
            if (p < 0 || p >= n || q < 0 || q >= m) continue;
            if (count + 1 > k) continue;
            if (check[p][q][count + 1] != -1) continue;
            bfsQ.push({p, q, count + 1});
            check[p][q][count + 1] = check[x][y][count] + 1;
        }
    }
    int ans = INF;
    for (int i = 0; i <= k; i++) {
        if (check[n - 1][m - 1][i] == -1) continue;
        ans = min(ans, check[n - 1][m - 1][i]);
    }
    if (ans == INF) {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans << '\n';
}