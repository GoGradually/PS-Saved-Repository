#include <bits/stdc++.h>
#define ll long long
#define INF ((int)1e9 + 10)
#define lINF ((ll)1e18 + 10LL)
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    vector<int> start(n + 1, 0);
    for (int c = 0; c < t; c++) {
        int b, d, k;
        cin >> b >> d >> k;
        for (int i = b; i <= n; i += b) {
            if (d == 0) start[i - 1] -= k;
            if (d == 1) start[i - 1] += k;
            start[i - 1] = (start[i - 1] + m) % m;
        }
        set<pair<int, int>> s;
        // 같은 수 찾기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] != 0 && arr[i][j] == arr[i][(j + 1) % m]) {
                    s.insert({i, j});
                    s.insert({i, (j + 1) % m});
                }
                if (i == n - 1) continue;
                if (arr[i][j] != 0 &&
                    arr[i][j] ==
                        arr[i + 1][(j - start[i] + start[i + 1] + m) % m]) {
                    s.insert({i, j});
                    s.insert({i + 1, (j - start[i] + start[i + 1] + m) % m});
                    // 0 0 |3 0 0
                    // 0 0 0 0 |3
                }
            }
        }

        for (auto& [x, y] : s) {
            arr[x][y] = 0;
        }

        if (s.empty()) {
            int sum = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] == 0) continue;
                    sum += arr[i][j];
                    cnt++;
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] == 0) continue;
                    if (arr[i][j] * cnt < sum) {
                        arr[i][j]++;
                    } else if (arr[i][j] * cnt > sum) {
                        arr[i][j]--;
                    }
                }
            }
        }
    }

    int val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != -1) val += arr[i][j];
        }
    }
    cout << val << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
