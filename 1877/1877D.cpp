#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 998244353LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    vector<ll> pow2(100001);
    pow2[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    int n;
    cin >> n;
    vector<ll> arr(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; i * j <= n; j++) {
            arr[i] = max(arr[i], arr[i * j]);
        }
    }
    map<ll, ll> can;
    for (int i = 1; i <= n; i++) {
        can[arr[i]]++;
    }
    map<ll, ll> psum;
    ll before = 0;
    for (auto it = can.begin(); it != can.end(); it++) {
        psum[it->first] = before;
        before += it->second;
        before %= MOD;
    }

    for (auto it = can.begin(); it != can.end(); it++) {
        ans += ((it->first) * (pow2[it->second] - 1) % MOD) *
               (pow2[psum[it->first]]) % MOD;
        ans %= MOD;
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
*int 오버플로우, out of bounds
*특수한 경우(n=1?)
*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기
*한가지 접근 방식에 얽메이지 말기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론" {greedy, D&C, DP, graph}(문제 특징의 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.

*/