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
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 1; i + j - 1 < n && i + j - 1 >= 0 && i - j >= 0; j++) {
            dp[i - j][i + j] = dp[i - j + 1][i + j - 1];
            dp[i - j][i + j] -=
                a[i - j] * b[i - j] + a[i + j - 1] * b[i + j - 1];
            dp[i - j][i + j] +=
                a[i - j] * b[i + j - 1] + a[i + j - 1] * b[i - j];
        }
        for (int j = 0; i + j + 1 <= n && i - j >= 0; j++) {
            dp[i - j][i + j + 1] = dp[i - j + 1][i + j];
            dp[i - j][i + j + 1] -= a[i - j] * b[i - j] + a[i + j] * b[i + j];
            dp[i - j][i + j + 1] += a[i - j] * b[i + j] + a[i + j] * b[i - j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        ans += a[i] * b[i];
    }
    cout << ans << '\n';
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
1. int 오버플로우, out of bounds
2. 특수한 경우(n=1?)
3. 잘못된 가정 & 증명

*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기, 구하고자 하는 것의 계층구조 표현하기.
*한가지 접근 방식에 얽메이지 말기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"(문제 특징의 "증명"으로 아이디어)
// {BruteForce, greedy, D&C, DP, graph, math}
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화)
// 3. cutting | 구현(차근차근 단순화 & 최적화)

/*
take notes.
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!

*/

// commit 시 피드백할 것 Message로 남겨두기!!
// 틀리면 느낌표 추가하기