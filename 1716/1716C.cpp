#include <bits/stdc++.h>
#define ll long long
#define INF (ll)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    ll m;
    cin >> m;
    vector<vector<ll>> arr(2, vector<ll>(m + 1));
    for (ll i = 1; i <= m; i++) {
        cin >> arr[0][i];
    }
    for (ll i = 1; i <= m; i++) {
        cin >> arr[1][i];
    }
    vector<vector<ll>> circuit(2, vector<ll>(m + 1));
    circuit[0][0] = lINF + 2000000;
    circuit[1][0] = lINF + 2000000;
    ll x = 0;
    for (ll i = 0; i < m; i++) {
        ll nowPos = m - i;
        if (x < arr[0][nowPos] + 2 * (i + 1) || x < arr[1][nowPos] + 1) {
            if (x < arr[1][nowPos] + 1) {
                x = arr[1][nowPos] + 1;
            }
            if (x < arr[0][nowPos] + 2 * (i + 1)) {
                if (nowPos != 1)
                    x = arr[0][nowPos] + 2 * (i + 1);
                else
                    x++;
            }
        } else {
            x++;
        }
        circuit[0][nowPos] = x;
    }
    x = 0;
    for (ll i = 0; i < m; i++) {
        ll nowPos = m - i;
        if (x < arr[0][nowPos] + 1 || x < arr[1][nowPos] + 2 * (i + 1)) {
            if (x < arr[0][nowPos] + 1) {
                x = arr[0][nowPos] + 1;
            }
            if (x < arr[1][nowPos] + 2 * (i + 1)) {
                x = arr[1][nowPos] + 2 * (i + 1);
            }
        } else {
            x++;
        }
        circuit[1][nowPos] = x;
    }
    ll nowPos = 0;
    ll ans = lINF + 2000000;
    ans = max(m * 2 - 1, circuit[nowPos][1]);
    nowPos = 1 - nowPos;
    x = arr[1][1] + 1;
    for (ll i = 1; i < m; i++) {
        if (ans > max(x + (m - i) * 2, x + circuit[nowPos][i + 1])) {
            ans = max(x + (m - i) * 2, x + circuit[nowPos][i + 1]);
        }
        if (arr[nowPos][i + 1] > x) x = arr[nowPos][i + 1];
        nowPos = 1 - nowPos;
        x++;
        if (arr[nowPos][i + 1] > x) x = arr[nowPos][i + 1];
        x++;
    }
    cout << min(x, ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll T = 1;
    cin >> T;
    while (T--) Solve();
    return 0;
}

/*
찾아야 할 것들
*ll 오버플로우, out of bounds
*특수한 경우(n=1?)
*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기
*한가지 접근 방식에 얽메이지 말기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론" {greedy, D&C, DP, graph, math}(문제 특징의 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.

*/

// commit 시 피드백할 것 Message로 남겨두기!!
