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
    vector<pair<int, int>> arr(n);
    vector<pair<int, int>> ind;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = {b, a};
        ind.push_back({a, 1});
        ind.push_back({b, -1});
    }
    sort(ind.begin(), ind.end());
    for (int i = 0; i < ind.size(); i++) {
        mp[ind[i].first] = i + 1;
    }
    for (int i = 0; i < ind.size(); i++) {
        ind[i].first = mp[ind[i].first];
    }
    map<int, int> start;
    for (int i = 0; i < n; i++) {
        arr[i].first = mp[arr[i].first];
        arr[i].second = mp[arr[i].second];
        start[arr[i].first] = arr[i].second;
    }
    // fenwick tree init
    vector<ll> fenwick(ind.size() + 10, 0);
    auto sum = [&](int i) -> int {
        int ret = 0;
        while (i) {
            ret += fenwick[i];
            i -= (i & -i);
        }
        return ret;
    };
    auto update = [&](int i, int diff) {
        while (i <= n * 2) {
            fenwick[i] += diff;
            i += (i & -i);
        }
    };

    ll ans = 0;
    for (int i = 0; i < ind.size(); i++) {
        if (ind[i].second == 1) {
            update(ind[i].first, 1);
        } else {
            ans += sum(start[ind[i].first] - 1);
            update(start[ind[i].first], -1);
        }
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

------
     ------
-10 +1
-8 +4
-5 +3
-3 +2
-2 -1
-1 -2
1 +6
2 +5
4 -3
5 -4
8 -5
9 -6
*/

// commit 시 피드백할 것 Message로 남겨두기!!~ㅊ
