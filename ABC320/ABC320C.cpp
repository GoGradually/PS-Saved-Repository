#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n;
    cin >> n;
    string str[3];
    for (int i = 0; i < 3; i++) {
        cin >> str[i];
    }
    vector<vector<vector<int>>> arr(3, vector<vector<int>>(10, vector<int>()));
    int ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool tag1 = false;
            if (i == j) {
                tag1 = true;
                j += n;
            }
            if (str[0][i] == str[1][j % n]) {
                bool tag2 = false;
                bool tag3 = false;
                for (int k = 0; k < n; k++) {
                    if (i == k) {
                        tag2 = true;
                        k += n;
                    }
                    if (j == k) {
                        tag3 = true;
                        k += n;
                    }
                    if (str[0][i] == str[2][k % n]) {
                        ans = min(ans, max({ i, j, k }));
                    }
                    if (tag2) {
                        k -= n;
                        tag2 = false;
                    }
                    if (tag3) {
                        k -= n;
                        tag3 = false;
                    }
                }
            }
            if (tag1) {
                j -= n;
                tag1 = false;
            }
        }
    }
    if (ans == INF)cout << -1 << '\n';
     else cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
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

/*
take notes.
겹치는 릴에 대한 해결법
해당 릴 골랐을 때 나머지 최소 수?

*/