#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n[3];
    cin >> n[0] >> n[1] >> n[2];
    vector<vector<ll>> arr(3, vector<ll>());
    ll sum[3] = {0, 0, 0};
    ll mn[3] = {lINF, lINF, lINF};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n[i]; j++) {
            ll temp;
            cin >> temp;
            arr[i].push_back(temp);
            sum[i] += temp;
            mn[i] = min(mn[i], temp);
        }
    }

    ll ans = 0;

    ans = max(ans, sum[0] + sum[1] - sum[2]);
    ans = max(ans, sum[0] + sum[2] - sum[1]);
    ans = max(ans, sum[2] + sum[1] - sum[0]);
    ans = max(ans, sum[0] + sum[1] + sum[2] - 2 * mn[1] - 2 * mn[2]);
    ans = max(ans, sum[0] + sum[1] + sum[2] - 2 * mn[0] - 2 * mn[2]);
    ans = max(ans, sum[0] + sum[1] + sum[2] - 2 * mn[0] - 2 * mn[1]);
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