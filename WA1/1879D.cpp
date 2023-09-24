#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 998244353LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> psum(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        psum[i + 1] = psum[i] ^ arr[i];
    }
    // debug
    ll ans1 = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j < i; j++) {
            ans1 += ((psum[i] ^ psum[j]) * (i - j))%MOD;
            ans1 %= MOD;
        }
    }
    cout << ans1 << '\n';
    //
    ll ans = 0;
    for (int i = 0; i < 30; i++) {
        vector<pair<int, ll>> check;
        check.push_back({arr[0] & 1, 1});
        arr[0] >>= 1;
        for (int j = 1; j < n; j++) {
            if ((arr[j] & 1) == check.back().first && check.back().first == 0) {
                check.back().second++;
            } else {
                check.push_back({arr[j] & 1, 1});
            }
            arr[j] >>= 1;
        }
        for (int j = 0; j < check.size(); j++) {
            if (check[j].first == 1) {
                ll left = 0, right = 0;
                if (j > 0) {
                    if (check[j - 1].first == 0) {
                        left = check[j - 1].second;
                    }
                }
                if (j < check.size() - 1) {
                    if (check[j + 1].first == 0) {
                        right = check[j + 1].second;
                    }
                }
            }
        }
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
// 1. "추론"(문제 특징의 증명으로 아이디어){greedy, D&C, DP, graph}
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. cutting | 구현

/*
take notes.

*/