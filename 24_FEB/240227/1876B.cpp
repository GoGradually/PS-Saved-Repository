#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 998244353LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i + 1);
    }
    vector<set<int>> index(n + 1);
    set<int> remain;
    for (int i = 1; i <= n; i++) {
        remain.insert(i);
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                index[i].insert(j);
                index[i].insert(i / j);
            }
        }
    }
    ll ans = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        set<int> now;
        for (int i = 0; i < it->second.size(); i++) {
            for (auto &&j : index[it->second[i]]) {
                if (remain.find(j) != remain.end()) {
                    now.insert(j);
                    remain.erase(j);
                }
            }
        }
        ll val = arr[it->second[0] - 1];
        // 2^남은 수 * (2^현재 가능 수 - 1) * val
        ll val1 = 1;
        ll tag = remain.size();
        ll a = 2;
        while (tag > 0) {
            if (tag & 1) {
                val1 *= a;
                val1 %= MOD;
            }
            a *= a;
            a %= MOD;
            tag /= 2;
        }
        val *= val1;
        val %= MOD;
        val1 = 1;
        tag = now.size();
        a = 2;
        while (tag > 0) {
            if (tag & 1) {
                val1 *= a;
                val1 %= MOD;
            }
            a *= a;
            a %= MOD;
            tag /= 2;
        }
        val1--;
        val *= val1;
        val %= MOD;
        ans += val;
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
// 1. "추론"(문제 특징의 "증명"으로 아이디어){greedy, D&C, DP, graph, math}
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화)
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!

*/

// commit 시 피드백할 것 Message로 남겨두기!!