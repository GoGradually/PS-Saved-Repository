#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    if (m == 1) {
        cout << 0 << '\n';
        for (int i = 0; i < n; i++) {
            cout << 0 << '\n';
        }
        return;
    }
    if (n == 1) {
        cout << 2 << '\n';
        for (int i = 0; i < m; i++) {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    arr[0][0] = m - 1;
    for (int i = 1; i < m; i++) {
        arr[0][i] = i - 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < m; j++) {
            arr[i][j] = arr[i - 1][j - 1];
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = j; i < n; i++) {
            arr[i][j] = m - 1 - j;
        }
    }

    if (m % 2 == 1) {
        for (int i = m / 2; i < n; i++) {
            swap(arr[i][0], arr[i][m / 2]);
        }
    }
    cout << min(n + 1, m) << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) Solve();
    return 0;
}

/*
찾아야 할 것들
*int 오버플로우, out of bounds
*특수한 경우(n=1?)
*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기
*한가지 접근 방식에 얽메이지 말기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"({greedy, D&C, DP, graph}, 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"