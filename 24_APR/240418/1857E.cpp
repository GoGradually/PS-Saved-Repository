#include <bits/stdc++.h>
#define ll long long
#define INF ((ll)1e9 + 10)
#define lINF ((ll)1e18 + 10LL)
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

bool go(ll root, ll val) {
    if (root * root <= val)
        return true;
    else
        return false;
}

ll binary_search(ll x) {
    ll left = 0, right = INF * 5;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (go(mid, x)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return right;
}

void Solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    map<ll, ll> cnt;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    int q;
    cin >> q;
    vector<ll> ans(q);
    for (int i = 0; i < q; i++) {
        ll b, c;
        cin >> b >> c;
        if (b * b - c * 4 >= 0) {
            ll decision = binary_search(b * b - c * 4);
            ll val1 = (b + decision) / 2;
            ll val2 = (b - decision) / 2;
            if (val1 + val2 != b || val1 * val2 != c) continue;
            if (val1 == val2)
                ans[i] = cnt[val1] * (cnt[val1] - 1) / 2;
            else
                ans[i] = cnt[val1] * cnt[val2];
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
1. int 오버플로우, out of bounds
2. 특수한 경우(n=1?)
3. 잘못된 가정 & 증명

*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기, 구하고자 하는 것의 계층구조 표현하기.
*한가지 접근 방식에 얽메이지 말기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"(문제 알고리즘/특징의 "증명"으로 아이디어)
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