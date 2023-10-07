#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 998244353LL;

using namespace std;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll mod_inv(ll val) {
    ll mod2 = MOD - 2;
    ll ret = 1;
    while (mod2 > 0) {
        if (mod2 & 1) {
            ret *= val;
            ret %= MOD;
        }
        val *= val;
        val %= MOD;
        mod2 >>= 1;
    }
    return ret;
}

void Solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> dp(1000000);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    ll modn = mod_inv(n);
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            dp[i + arr[j]] += dp[i] * modn;
            dp[i + arr[j]] %= MOD;
        }
    }
    ll sum1 = 0;

    for (ll i = 0; i <= x; i++) {
        if (i + arr[0] > x) {
            sum1 += dp[i] * modn;
            sum1 %= MOD;
        }
    }
    cout << sum1 << '\n';
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
// 1. "추론" (a→c에서 a→b→c를 만드는 "b" 찾기)
// (문제 특징의 증명으로 아이디어){greedy, D&C, DP, graph}
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.

*/
