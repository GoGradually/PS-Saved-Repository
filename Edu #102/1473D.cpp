#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    int now = 0;
    vector<int> pre_mn(n + 2, 0), pre_mx(n + 2, 0), ret(n + 2, 0);
    vector<int> suf_mn(n + 2, 0), suf_mx(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        if (str[i - 1] == '+') {
            now++;
        } else {
            now--;
        }
        pre_mx[i] = max(pre_mx[i - 1], now);
        pre_mn[i] = min(pre_mn[i - 1], now);
        ret[i] = now;
    }
    for (int i = n; i >= 1; i--) {
        int val = 0;
        if (str[i - 1] == '+') {
            val++;
        } else {
            val--;
        }
        suf_mn[i] = min(0, suf_mn[i + 1] + val);
        suf_mx[i] = max(0, suf_mx[i + 1] + val);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        now = 0;
        int pre_min = 0, pre_max = 0, suf_min = 0, suf_max = 0;
        pre_min = pre_mn[l - 1];
        pre_max = pre_mx[l - 1];
        now = ret[l - 1];

        suf_min = now + suf_mn[r + 1];
        suf_max = now + suf_mx[r + 1];
        cout << max(pre_max, suf_max) - min(pre_min, suf_min) + 1 << '\n';
    }
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

*/

// commit 시 피드백할 것 Message로 남겨두기!!