#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> horizon(n, vector<char>(m - 1, 'R'));
    vector<vector<char>> vertical(n - 1, vector<char>(m, 'R'));
    if ((n + m - 2) % 4 == k % 4) {
        if ((n + m - 2) / 4 <= k / 4) {
            cout << "YES\n";
            vertical[0][0] = 'B';
            vertical[0][1] = 'B';
            int cnt = 1;
            int index = 1;
            while (index < m - 1) {
                if (cnt == 1) {
                    horizon[0][index] = 'B';
                }
                cnt = 1 - cnt;
                index++;
            }
            index = 0;
            while (index < n - 1) {
                if (cnt == 1) {
                    vertical[index][m - 1] = 'B';
                }
                cnt = 1 - cnt;
                index++;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m - 1; j++) {
                    cout << horizon[i][j] << ' ';
                }
                cout << '\n';
            }
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m; j++) {
                    cout << vertical[i][j] << ' ';
                }
                cout << '\n';
            }

        } else {
            cout << "NO\n";
        }
    } else if ((n + m) % 4 == k % 4) {
        if ((n + m) / 4 <= k / 4) {
            cout << "YES\n";
            horizon[0][0] = 'B';
            horizon[1][0] = 'B';
            int cnt = 1;
            int index = 1;
            while (index < m - 1) {
                if (cnt == 1) {
                    horizon[0][index] = 'B';
                }
                cnt = 1 - cnt;
                index++;
            }
            index = 0;
            while (index < n - 1) {
                if (cnt == 1) {
                    vertical[index][m - 1] = 'B';
                }
                cnt = 1 - cnt;
                index++;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m - 1; j++) {
                    cout << horizon[i][j] << ' ';
                }
                cout << '\n';
            }
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m; j++) {
                    cout << vertical[i][j] << ' ';
                }
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
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
// 1. "추론"(문제 특징의 "증명"으로 아이디어){greedy, D&C, DP, graph, math}
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화)
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.

*/

// commit 시 피드백할 것 Message로 남겨두기!!