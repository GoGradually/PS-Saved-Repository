#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    ll n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<ll> appear(n + m + 1, -1);
    vector<ll> cnt(n + m + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        appear[arr[i]] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        cnt[arr[a]] += i - appear[arr[a]];
        appear[arr[a]] = -1;
        appear[b] = i;
        arr[a] = b;
    }
    for (int i = 0; i < n; i++) {
        cnt[arr[i]] += m - appear[arr[i]] + 1;
        appear[arr[i]] = -1;
    }

    ll ans = 0;
    ll sum = m * (m + 1) / 2;
    for (int i = 1; i <= n + m; i++) {
        ll val1 = (m - cnt[i]) * (m - cnt[i] + 1) / 2;
        ans += sum - val1;
    }
    cout << ans << '\n';
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
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!

*/

// commit 시 피드백할 것 Message로 남겨두기!!